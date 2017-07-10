#ifndef SERVER_THREAD_H_INCLUDED
#define SERVER_THREAD_H_INCLUDED

#include <functional>
#include <thread>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "threadpool.h"
#include "connection.h"
#include "client_directory.h"

class Server_thread 
{
	private:	
		int portnum; 
		Threadpool &threadpool; 
		std::thread *thread; 
	public:
		Server_thread(int portnum, Threadpool &threadpool); 
		void start(); 
		void listen_for_clients();
		void spawn_connection(int socketfd);
		~Server_thread(); 
}; 
#endif // SERVER_THREAD_H_INCLUDED
