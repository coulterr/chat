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
#include <string.h>

class Communicator 
{
	private:
		int socketfd; 

	public: 
		Communicator(int socketfd);
		bool send_message(std::string message);
		std::string recv_message();
		~Communicator();
};

#endif 

