#ifndef CLIENT_DIRECTORY_H_INCLUDED
#define CLIENT_DIRECTORY_H_INCLUDED

#include <string>
#include <iostream>
#include <map>

#include <semaphore.h>

#include "client.h"

class Client_directory
{
	private:
		std::map<std::string, Client*> clients;
		sem_t lock; 
	public:
		Client_directory(); 
		bool contains_client(std::string name); 
		bool add_client(Client &client); 
		bool dispatch_message(std::string name, std::string message); 
		void remove_client(std::string name); 
		void list_clients(); 
		~Client_directory();
};
#endif // CLIENT_DIRECTORY_H_INCLUDED
