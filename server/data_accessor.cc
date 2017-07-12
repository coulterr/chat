#include "headers/data_accessor.h"
#include "headers/sqlite3.h"

const std::string Data_accessor::GET_USER_STMT = std::string("SELECT id, password FROM user WHERE name=?;"); 

Data_accessor::Data_accessor(std::string path)
{		
	sqlite3_open(path.c_str(), &database); 

}

void Data_accessor::get_user_by_id(int id)
{
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
}

User *Data_accessor::get_user_by_name(std::string name)
{
	sqlite3_stmt *statement; 
	sqlite3_prepare_v2(database, (const char *) GET_USER_STMT.c_str(), -1, &statement, NULL); 
	sqlite3_bind_text(statement, 1, (const char *) name.c_str(), -1, 0); 
	int status = sqlite3_step(statement); 
	if(status == SQLITE_DONE) return NULL; 

	int id = sqlite3_column_int(statement, ID_INDEX); 
	std::string password((char *) sqlite3_column_blob(statement, PASSWORD_INDEX)); 

	sqlite3_step(statement); 
	sqlite3_finalize(statement); 

	User *user = new User(id, name, password); 
	return user; 
	
}

Data_accessor::~Data_accessor()
{
	sqlite3_close(database); 
}
