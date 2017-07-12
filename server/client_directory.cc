#include "headers/client_directory.h"

Client_directory::Client_directory()
{
	clients = std::map<std::string, Client*>(); 
	lock = sem_t();  		
	sem_init(&lock, 0, 1); 
}

bool Client_directory::contains_client(std::string name)
{
	if(clients.find(name) == clients.end()){
		return false; 
	}else{
		return true; 
	}
}

bool Client_directory::add_client(std::string name, Client &client)
{
	bool ret = true; 
	sem_wait(&lock); 
		if (contains_client(name)) {
			ret = false; 			
		}else {
			clients[name] = &client; 
		}
	sem_post(&lock); 

	return ret; 
}

bool Client_directory::dispatch_message(std::string name, std::string message)
{
	bool ret = true; 
	
	sem_wait(&lock); 	
		if(contains_client(name)) {
			ret = (*clients[name]).send_message(message); 	
		}else {
			ret = false; 
		}
	sem_post(&lock); 

	return ret; 
}

void Client_directory::remove_client(std::string name)
{
	sem_wait(&lock); 

		clients.erase(name); 
	
	sem_post(&lock); 
}

void Client_directory::list_clients()
{
	sem_wait(&lock); 

		std::map<std::string, Client*>::iterator i; 
		int count = 1; 
		for(i = (clients).begin(); i != (clients).end(); ++i)
		{
			std::cout << count << ": " << (*i).first << std::endl;  	
			++count; 
		}	
		
	sem_post(&lock); 
}

Client_directory::~Client_directory()
{
}
//TO BE IMPLEMENTED
