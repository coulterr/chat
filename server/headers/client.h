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
#include "user.h"

class Client
{
	private:
		std::string name; 
		Communicator comm; 
		User *user; 

	public:
		Client(int socketfd); 
		bool send_message(std::string message); 
		std::string recv_message(); 
		void set_user(User *user); 
		User &get_user();  
		~Client();
};
#endif // CLIENT_H_INCLUDED
