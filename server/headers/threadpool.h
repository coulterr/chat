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
#include "../headers/connection.h"

class Threadpool
{
	private:
		std::queue<Connection*> connections_; 
		std::vector<std::thread> threads_;
		sem_t empty_; 
		sem_t full_; 

		 
	public:
		Threadpool(int threadcount); 
		void start_spinning(); 
		void add_connection(Connection *connection); 
		~Threadpool();
};
#endif // THREADPOOL_H_INCLUDED
