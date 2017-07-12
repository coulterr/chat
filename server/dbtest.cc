#include "headers/data_accessor.h"
#include "headers/user.h"
int main()
{
	Data_accessor accessor(std::string("database.db")); 
	accessor.get_user_by_id(1); 
	User *user = accessor.get_user_by_name("Bob"); 
	if(user == NULL) {
		std::cout << "User not found" << std::endl; 
	}else {
		(*user).print(); 
	}

	accessor.add_user(std::string("Bob"), std::string("yyy")); 

	
}

