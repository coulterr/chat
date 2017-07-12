#ifndef USER_H
#define USER_H

#include <string>


class User
{
	private: 
		int id; 
		std::string name; 
		std::string password; 
	public: 
		User(int id, std::string name, std::string password); 
		bool validate_password(std::string attempt); 
		~User(); 
};



#endif 
