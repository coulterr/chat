#include "headers/data_accessor.h"
#include "headers/sqlite3.h"

const char Data_accessor::GET_USER_STMT[] = "SELECT id, password FROM user WHERE name=?;"; 
const char Data_accessor::ADD_USER_STMT[] = "INSERT INTO user (name, password) VALUES (?, ?);";
const char Data_accessor::GET_FRIEND_ENTRIES_STMT[] = "SELECT id, user FROM friend_entries WHERE owner=?;";
const char Data_accessor::GET_INCOMING_FRIEND_REQUESTS_STMT[] = "SELECT id, sender FROM friend_requests WHERE recipient=?;";
const char Data_accessor::GET_OUTGOING_FRIEND_REQUESTS_STMT[] = "SELECT id, recipient FROM friend_requests WHERE sender=?;"; 
const char Data_accessor::ADD_FRIEND_REQUEST_STMT[] = "INSERT INTO friend_request (name, password, date) VALUES (?, ?, ?);";
const char Data_accessor::GET_FRIEND_REQUEST_STMT[] = "SELECT * FROM friend_request WHERE sender=? AND recipient=?;"; 
const char Data_accessor::REMOVE_FRIEND_REQUEST_STMT[] = "DELETE FROM friend_request WHERE id=?;"; 
const char Data_accessor::ADD_FRIEND_ENTRY_STMT[] = "INSERT INTO friend_entry (owner, user) VALUES (?, ?);"; 
const char Data_accessor::REMOVE_FRIEND_ENTRY_STMT[] = "DELETE FROM friend_entry WHERE owner=? AND user=?;"; 


Data_accessor::Data_accessor(std::string path) 
{		
	sem_init(&lock, 0, 1); 
	sqlite3_open(path.c_str(), &database); 

}


void Data_accessor::get_user_by_id(int id)
{
	sem_wait(&lock);
		
		std::string name, password;
		
		std::string query_string = std::string("SELECT name, password FROM user WHERE id=\'") + std::to_string(id) + "\';";   
		const char *query = (const char *) query_string.c_str(); 
		
		sqlite3_stmt *statement; 
		sqlite3_prepare(database, query, -1, &statement, NULL); 
		
		//do stuff with that statement
		sqlite3_step(statement); 
		
		name = std::string((char *)sqlite3_column_blob(statement, NAME_INDEX));
		password = std::string((char *)sqlite3_column_blob(statement, PASSWORD_INDEX));
		
		sqlite3_step(statement); 
		sqlite3_finalize(statement); 
		
		std::cout << name << ": " << password << std::endl; 
	
	sem_post(&lock); 
}


bool Data_accessor::add_user(std::string name, std::string password) 
{
	bool success; 
	
	sem_wait(&lock);
		
		sqlite3_stmt *check_statement; 
		sqlite3_prepare_v2(database, GET_USER_STMT, -1, &check_statement, NULL); 
		sqlite3_bind_text(check_statement, 1, (const char *) name.c_str(), -1, 0); 
		int status = sqlite3_step(check_statement); 
		sqlite3_finalize(check_statement); 

		if(status == SQLITE_DONE)
		{
			sqlite3_stmt *statement; 
			sqlite3_prepare_v2(database, ADD_USER_STMT, -1, &statement, NULL); 
			sqlite3_bind_text(statement, 1, (const char *) name.c_str(), -1, 0); 		
			sqlite3_bind_text(statement, 2, (const char *) password.c_str(), -1, 0); 
			int status = sqlite3_step(statement); 
			sqlite3_finalize(statement);  
			success = true; 
		}

	sem_post(&lock);
	return success;
}


User *Data_accessor::get_user_by_name(std::string name)
{
	User *user = NULL; 
	sem_wait(&lock);
		
		sqlite3_stmt *statement; 
		sqlite3_prepare_v2(database, GET_USER_STMT, -1, &statement, NULL); 
		sqlite3_bind_text(statement, 1, (const char *) name.c_str(), -1, 0); 
		int status = sqlite3_step(statement); 
		if(status != SQLITE_DONE)
		{
			int id = sqlite3_column_int(statement, ID_INDEX); 
			std::string password((char *) sqlite3_column_blob(statement, PASSWORD_INDEX)); 

			sqlite3_step(statement); 
			sqlite3_finalize(statement); 
			user = new User(id, name, password); 
		}

	sem_post(&lock);
	
	return user; 
}


std::vector<Friend_entry> Data_accessor::get_friend_entries(int owner_id) 
{
	std::vector<Friend_entry> entries; 

	sem_wait(&lock); 

		sqlite3_stmt *statement; 
		sqlite3_prepare_v2(database, GET_FRIEND_ENTRIES_STMT, -1, &statement, NULL); 
		sqlite3_bind_int(statement, 1, owner_id); 
		int status = sqlite3_step(statement); 
		while(sqlite3_step(statement) != SQLITE_DONE)
		{
			Friend_entry entry; 
			entry.owner = owner_id; 
			entry.id = sqlite3_column_int(statement, 1); 
			entry.user = sqlite3_column_int(statement, 2); 	
			entries.push_back(entry); 
		}
		
		sqlite3_finalize(statement); 

	sem_post(&lock); 

	return entries; 
}


std::vector<Friend_request> Data_accessor::get_incoming_friend_requests(int recipient)
{
	std::vector<Friend_request> requests; 

	sem_wait(&lock); 

		sqlite3_stmt *statement; 
		sqlite3_prepare_v2(database, GET_INCOMING_FRIEND_REQUESTS_STMT, -1, &statement, NULL); 
		sqlite3_bind_int(statement, 1, recipient); 
		int status = sqlite3_step(statement); 
		while(sqlite3_step(statement) != SQLITE_DONE)
		{
			Friend_request request; 
			request.recipient = recipient; 
			request.id = sqlite3_column_int(statement, 1); 
			request.sender = sqlite3_column_int(statement, 2); 	
			requests.push_back(request); 
		}
		
		sqlite3_finalize(statement); 

	sem_post(&lock); 

	return requests;  
}


std::vector<Friend_request> Data_accessor::get_outgoing_friend_requests(int sender)
{
	std::vector<Friend_request> requests; 

	sem_wait(&lock); 

		sqlite3_stmt *statement; 
		sqlite3_prepare_v2(database, GET_OUTGOING_FRIEND_REQUESTS_STMT, -1, &statement, NULL); 
		sqlite3_bind_int(statement, 1, sender); 
		int status = sqlite3_step(statement); 
		while(sqlite3_step(statement) != SQLITE_DONE)
		{
			Friend_request request; 
			request.sender = sender; 
			request.id = sqlite3_column_int(statement, 1); 
			request.recipient = sqlite3_column_int(statement, 2); 	
			requests.push_back(request); 
		}
		
		sqlite3_finalize(statement); 

	sem_post(&lock); 

	return requests;  
}


bool Data_accessor::add_friend_request(int sender, int recipient, int date)
{
	bool success = true; 

	sem_wait(&lock); 
		
		bool exists = false; 	

		sqlite3_stmt *check_one; 
		sqlite3_prepare_v2(database, GET_FRIEND_REQUEST_STMT, -1, &check_one, NULL); 
		sqlite3_bind_int(check_one, 1, sender); 
		sqlite3_bind_int(check_one, 2, recipient); 
		if(sqlite3_step(check_one) != SQLITE_DONE) exists = true; 
		sqlite3_finalize(check_one); 

		sqlite3_stmt *check_two; 
		sqlite3_prepare_v2(database, GET_FRIEND_REQUEST_STMT, -1, &check_two, NULL); 
		sqlite3_bind_int(check_two, 1, recipient); 
		sqlite3_bind_int(check_two, 2, sender); 
		if(sqlite3_step(check_two) != SQLITE_DONE) exists = true; 
		sqlite3_finalize(check_two); 
			
		if(!exists) 	
		{
			sqlite3_stmt *statement; 
			sqlite3_prepare_v2(database, ADD_FRIEND_REQUEST_STMT, -1, &statement, NULL); 
			sqlite3_bind_int(statement, 1, sender); 
			sqlite3_bind_int(statement, 2, recipient); 
			sqlite3_bind_int(statement, 3, date); 
		}else success = false; 
			
	sem_post(&lock); 

	return success; 
}


void Data_accessor::remove_friend_request(int id)
{
	
	sem_wait(&lock); 

	sem_post(&lock); 
}


bool Data_accessor::add_friend_entry_pair(int a, int b)
{
	bool success = true; 

	sem_wait(&lock); 

	sem_post(&lock); 
}


void Data_accessor::remove_friend_entry_pair(int a, int b)
{
	sem_wait(&lock); 

	sem_post(&lock); 

}


Data_accessor::~Data_accessor()
{
	sqlite3_close(database); 
}
