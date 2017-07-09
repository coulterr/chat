#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include <iostream>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 

#include "communicator.h"

class Client
{
	private:
		std::string name; 
		Communicator *comm; 

	public:
		Client(Communicator *comm); 
		void set_name(std::string name);  
		std::string get_name();
		bool send_message(std::string message); 
		std::string recv_message(); 
		~Client();
};
#endif // CLIENT_H_INCLUDED
