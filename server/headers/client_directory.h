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
		std::map<int, Client*> clients;
		sem_t lock; 
	public:
		Client_directory(); 
		bool contains_client(int id); 
		bool add_client(int id, Client &client); 
		bool dispatch_message(int id, std::string message); 
		void remove_client(int id); 
		void list_clients(); 
		~Client_directory();
};
#endif // CLIENT_DIRECTORY_H_INCLUDED
