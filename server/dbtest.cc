#include "headers/data_accessor.h"
#include "headers/user.h"
int main()
{
	Data_accessor accessor("database.db"); 
	std::cout << "Getting user by name \"Riley\"..." << std::endl; 	
	User *riley = accessor.get_user_by_name("Riley"); 
	if (riley == NULL) {
		std::cout << "get_user(\"Riley\") returned NULL" << std::endl; 
	}else {
		std::cout << "It worked!" << std::endl; 
		(*riley).print(); 
	}

	std::cout << "Adding user Bob, with password yyy..." << std::endl;
	bool success = accessor.add_user(std::string("Bob"), std::string("yyy")); 
	
	if (success) {
		std::cout << "It worked! Here's the user:" << std::endl; 
		User *bob = accessor.get_user_by_name("Bob"); 
		(*bob).print(); 
	}else {
		std::cout << "It didn't work." << std::endl;
	}


	std::cout << "Adding duplicate user Bob. This shouldn't work" << std::endl; 
	success = accessor.add_user(std::string("Bob"), std::string("yyy")); 

	if (success) {
		std::cout << "It worked... which is bad." << std::endl; 
	}else {
		std::cout << "It didn't work, which is good." << std::endl; 
	}

		




	
}

