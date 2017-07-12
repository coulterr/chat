#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>

#include <string.h>
#include <sqlite3.h>

#include "user.h"

class Data_accessor
{
	private:
		sqlite3 *database; 
		const int ID_INDEX = 0; 
		const int NAME_INDEX = 0; 
		const int PASSWORD_INDEX = 1; 
		static const std::string GET_USER_STMT;
	public:
		Data_accessor(std::string path); 
		void get_user_by_id(int id); 
		User *get_user_by_name(std::string name); 
		~Data_accessor(); 

};

#endif
