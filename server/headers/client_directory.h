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
		std::map<std::string, Client*> clients_;
		sem_t lock_; 
	public:
		Client_directory(); 
		bool contains_client(std::string name); 
		bool add_client(Client *cli); 
		bool dispatch_msg(std::string name, std::string msg); 
		void remove_client(std::string name); 
		void list_clients(); 
		~Client_directory();
};
#endif // CLIENT_DIRECTORY_H_INCLUDED
