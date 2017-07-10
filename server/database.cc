#include "headers/database.h"
#include "headers/sqlite3.h"

Database::Database(std::string path)
{		
	sqlite3_open(path.c_str(), &database); 

}

void Database::get_user_by_id(int id)
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


Database::~Database()
{
	sqlite3_close(database); 
}
