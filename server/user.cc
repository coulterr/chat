#include "headers/user.h"

User::User(int id, std::string name, std::string password)
:id(id), name(name), password(password)
{	
}

bool User::validate_password(std::string attempt)
{
	if(password.compare(attempt) == 0) return true; 
	return false; 
}



int User::get_id()
{
	return id; 
}

std::string User::get_name()
{
	return name;
}

bool User::has_friend(int id) 
{
	return true; 
}

void User::print()
{
	std::cout << "ID: " << id << std::endl; 
	std::cout << "NAME: " << name << std::endl; 
	std::cout << "PASSWORD: " << password << std::endl; 

}


User::~User(){}; 

