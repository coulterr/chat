#include "headers/data_accessor.h"
#include "headers/user.h"
int main()
{
	Data_accessor database(std::string("database.db")); 
	database.get_user_by_id(1); 
}

