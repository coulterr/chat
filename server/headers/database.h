#ifndef DATABASE_H
#define DATABASE_H

class Database
{
	private:
		sqlite3 *database; 
	public:
		Database(const char *path); 
		User get_user_by_id(std::string id); 
		~Database(); 

};

#endif
