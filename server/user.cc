
User::User(int id, std::string name, std::string password)
:id(id), name(name), password(password)
{	
}

User::validate_password(std::string attempt)
{
	if(password.compare(attempt) == 0) return true; 
	return false; 
}



User::~User(){}; 

