#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include <iostream>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> 

class Client
{
	private:
		std::string name_; 
		int sockfd_; 

	public:
		Client(std::string name, int sockfd); 
		Client(int sockfd); 
		void set_name(std::string name);  
		std::string get_name();
		bool send_msg(std::string msg); 
		std::string recv_msg(); 
		~Client();
};
#endif // CLIENT_H_INCLUDED
