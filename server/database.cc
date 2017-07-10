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


}

Database::~Database()
{
	sqlite3_close(database); 
}
