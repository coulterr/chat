#include "headers/client_directory.h"

Client_directory::Client_directory()
{
	clients = std::map<int, Client*>(); 
	lock = sem_t();  		
	sem_init(&lock, 0, 1); 
}

bool Client_directory::contains_client(int id)
{
	if(clients.find(id) == clients.end()){
		return false; 
	}else{
		return true; 
	}
}

bool Client_directory::add_client(int id, Client &client)
{
	bool ret = true; 
	sem_wait(&lock); 
		if (contains_client(id)) {
			ret = false; 			
		}else {
			clients[id] = &client; 
		}
	sem_post(&lock); 

	return ret; 
}

bool Client_directory::dispatch_message(int id, std::string message)
{
	bool ret = true; 
	
	sem_wait(&lock); 	
		if(contains_client(id)) {
			ret = (*clients[id]).send_message(message); 	
		}else {
			ret = false; 
		}
	sem_post(&lock); 

	return ret; 
}

void Client_directory::remove_client(int id)
{
	sem_wait(&lock); 

		clients.erase(id); 
	
	sem_post(&lock); 
}

void Client_directory::list_clients()
{
	sem_wait(&lock); 

		std::map<int, Client*>::iterator i; 
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
