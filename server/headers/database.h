#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>

#include <sqlite3.h>

class Database
{
	private:
		sqlite3 *database; 
		const int NAME_INDEX = 0; 
		const int PASSWORD_INDEX = 1; 
	public:
		Database(std::string path); 
		void get_user_by_id(int id); 
		~Database(); 

};

#endif
