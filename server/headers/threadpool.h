#ifndef THREADPOOL_H_INCLUDED
#define THREADPOOL_H_INCLUDED

#include <iostream>
#include <string>
#include <queue>
#include <thread> 
#include <vector>

#include <semaphore.h>
#include <sys/socket.h>

#include "client.h"
#include "connection.h"

class Threadpool
{
	private:
		Client_directory &directory; 
		std::queue<Client*> clients; 
		std::vector<std::thread*> threads;
		sem_t empty; 
		sem_t full; 

		 
	public:
		Threadpool(int threadcount, Client_directory &directory); 
		void start_spinning(); 
		void add_client(int socketfd); 
		~Threadpool();
};
#endif // THREADPOOL_H_INCLUDED
