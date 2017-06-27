#include "headers/client_listener.h"

Client_listener::Client_listener(Sock_reader *reader)
{
	reader_ = reader; 
}

void Client_listener::listen_for_messages()
{
	while(true)
	{
		std::string msg = (*reader_).recv_msg(); 
		std::cout << msg << std::endl; 
	}
}

Client_listener::~Client_listener()
{
	delete reader_; 
}
