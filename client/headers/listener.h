#ifndef	LISTENER_H
#define LISTENER_H

#include <iostream>
#include <unistd.h>
#include <iostream> 
#include <thread>
#include <string> 

#include <sys/types.h>
#include <sys/socket.h>

#include "communicator.h"

class Listener
{
	private: 
		Communicator *comm; 
		std::thread *thread; 
		void process_message(std::string message);
		void listen_for_messages();

	public: 
		Listener(Communicator *comm);
		void start_listening();
		~Listener();
};
#endif
