#ifndef SERVER_THREAD_H_INCLUDED
#define SERVER_THREAD_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <functional>
#include <thread>
#include "../headers/threadpool.h"
#include "../headers/connection.h"
#include "../headers/client_directory.h"

class Server_thread 
{
	private:	
		int portnum; 
		Threadpool *threadpool; 
		Client_directory *directory; 
		std::thread *thread; 
	public:
		Server_thread(int portnum, Threadpool *threadpool, Client_directory *directory); 
		void start(); 
		void listen_for_clients();
		void spawn_connection(int sockfd);
		~Server_thread(); 
}; 
#endif // SERVER_THREAD_H_INCLUDED