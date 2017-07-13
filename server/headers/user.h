#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <vector>
#include <semaphore.h>

class User
{
	private: 
		int id; 
		std::string name; 
		std::string password; 
		std::vector<int> friends; 
		sem_t lock; 
	public: 
		User(int id, std::string name, std::string password); 
		int get_id(); 
		std::string get_name(); 
		bool validate_password(std::string attempt); 
		bool has_friend(int id); 
		void add_friend(int id, std::string name); 
		void print(); 
		~User(); 
};



#endif 
