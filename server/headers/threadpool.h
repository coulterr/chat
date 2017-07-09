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
