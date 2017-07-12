#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User
{
	private: 
		int id; 
		std::string name; 
		std::string password; 
	public: 
		User(int id, std::string name, std::string password); 
		bool validate_password(std::string attempt); 
		void print(); 
		~User(); 
};



#endif 
