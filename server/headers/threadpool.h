#ifndef THREADPOOL_H_INCLUDED
#define THREADPOOL_H_INCLUDED

#include <sys/socket.h>
#include <iostream>
#include <string>
#include <queue>
#include <thread> 
#include <vector>
#include <semaphore.h>

#include "../headers/client.h"
#include "../headers/client_dir.h"
bool process_login(Client *cli); 
void start_listening(Client *cli); 


class Threadpool
{
	private:
		Client_dir *client_dir_; 
		std::queue<Client*> client_queue_; 
		std::vector<std::thread> threads_;
		sem_t empty_; 
		sem_t full_; 

		 
	public:
		Threadpool(Client_dir *client_dir); 
		void start_spinning(); 
		void add_client(Client *cli); 
		~Threadpool();
};
#endif // THREADPOOL_H_INCLUDED
