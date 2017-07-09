#ifndef ADMIN_THREAD_H
#define ADMIN_THREAD_H

#include <iostream>
#include <string>
#include <thread>

#include "threadpool.h"
#include "client_directory.h"

class Admin_thread
{
	private: 
		Threadpool *threadpool; 
		Client_directory *directory; 
		std::thread *thread; 
		void list_clients(); 
		void listen_for_commands(); 
	public: 
		Admin_thread(Threadpool *threadpool, Client_directory *directory); 
		void start(); 
		~Admin_thread(); 
		
};

#endif



