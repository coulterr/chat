#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include "../headers/client_listener.h"
#include "../headers/sock_writer.h"

class Client
{
	private:
		std::string name_; 
		Sock_writer *writer_; 
		Client_listener *listener_; 

	public:
		Client(std::string name, Sock_writer *writer, Client_listener *listener);
		std::string get_name();
		Sock_writer *get_writer();
		Client_listener *get_listener();
		~Client();
};
#endif // CLIENT_H_INCLUDED
