#include "headers/database.h"

Database::Database(std::string path)
{		
	sqlite3_open(path.c_str(), &database); 

}

void Database::get_user_by_id(int id)
{
	std::string name, password; 
	const char query[] = "SELECT name, password FROM user WHERE id=" + id + ";"; 
	sqlite3_stmt *statement; 
	sqlite3_prepare(database, query, -1, &statement, NULL); 
	//do stuff with that statement
	sqlite3_step(statement); 
	name = std::string((char *)sqlite3_column_blob(statement, NAME_INDEX));
	password = std::string((char *)sqlite3_column_blob(statement, PASSWORD_INDEX));
	sqlite3_step(statement); 
	sqlite3_finalize(statement); 
	//sqlite3_step to finish... might be unnecessary
	//sqlite3_finalize statement destroys statement "object"
	std::cout << name << ": " << password << std::endl; 

}

Database::~Database()
{
	sqlite3_close(database); 
}
