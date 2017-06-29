#ifndef CLIENT_DIR_H_INCLUDED
#define CLIENT_DIR_H_INCLUDED

#include "../headers/client.h"
#include <string>
#include <iostream>
#include <map>
#include <semaphore.h>

class Client_dir
{
	private:
		std::map<std::string, Client*> clients_;
		sem_t lock_; 
	public:
		Client_dir(); 
		bool contains_client(std::string name); 
		bool add_client(Client *cli); 
		bool dispatch_msg(std::string name, std::string msg); 
		void remove_client(std::string name); 
		void list_clients(); 
		~Client_dir();
};
#endif // CLIENT_DIR_H_INCLUDED
