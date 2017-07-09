#include "headers/client_directory.h"

Client_directory::Client_directory()
{
	clients_ = std::map<std::string, Client*>(); 
	lock_ = sem_t();  		
	sem_init(&lock_, 0, 1); 
}

bool Client_directory::contains_client(std::string name)
{
	if(clients_.find(name) == clients_.end()){
		return false; 
	}else{
		return true; 
	}
}

bool Client_directory::add_client(Client *cli)
{
	bool ret = true; 
	sem_wait(&lock_); 
		if ((*this).contains_client((*cli).get_name())) {
			ret = false; 			
		}else {
			clients_[(*cli).get_name()] = cli; 
		}
	sem_post(&lock_); 

	return ret; 
}

bool Client_directory::dispatch_msg(std::string name, std::string msg)
{
	bool ret = true; 
	
	sem_wait(&lock_); 	
		if((*this).contains_client(name)) {
			ret = (*clients_[name]).send_msg(msg); 	
		}else {
			ret = false; 
		}
	sem_post(&lock_); 

	return ret; 
}

void Client_directory::remove_client(std::string name)
{
	sem_wait(&lock_); 

		clients_.erase(name); 
	
	sem_post(&lock_); 
}

void Client_directory::list_clients()
{
	sem_wait(&lock_); 

		std::map<std::string, Client*>::iterator i; 
		int count = 1; 
		for(i = (clients_).begin(); i != (clients_).end(); ++i)
		{
			std::cout << count << ": " << (*(*i).second).get_name() << std::endl;  	
			++count; 
		}	
		
	sem_post(&lock_); 
}

Client_directory::~Client_directory()
{
}
//TO BE IMPLEMENTED