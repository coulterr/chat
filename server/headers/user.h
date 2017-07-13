#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <vector>

class User
{
	private: 
		int id; 
		std::string name; 
		std::string password; 
		std::vector<int> friends; 
	public: 
		User(int id, std::string name, std::string password); 
		int get_id(); 
		std::string get_name(); 
		bool validate_password(std::string attempt); 
		bool has_friend(int id); 
		void print(); 
		~User(); 
};



#endif 
