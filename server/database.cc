Database::Database(std::string path)
{		
	sqlite3_open(path.c_str(), &database); 

}

User Database::get_user_by_id(std::string id)
{
	const char query[] = ""; 
	sqlite3_stmt *statement; 
	sqlite3_prepare(database, query, -1, &statement, NULL); 
	//do stuff with that statement
	//sqlite3_step to evaluate up to single row
	//sqlite3_column multiple times for user fields
	//sqlite3_step to finish... might be unnecessary
	//sqlite3_finalize statement destroys statement "object"


}

Database::~Database()
{
	sqlite3_close(database); 
}
