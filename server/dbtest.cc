#include "headers/database.h"

int main()
{
	Database database("database.db"); 
	database.get_user_by_id(0); 
}

