#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <iostream>
#include <unistd.h>
#include <iostream> 
#include <thread>
#include <string> 

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class Communicator 
{
	private: 
		int socketfd; 
	public: 
		Communicator(int socketfd);
		std::string recv_message();
		void send_message(std::string message);
		~Communicator();
};


#endif
