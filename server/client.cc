#include "headers/client.h"

Client::Client(std::string name, Sock_writer *writer, Client_listener *listener) 
{
	name_ = name; 
	writer_ = writer; 
	listener_ = listener; 		
}

std::string Client::get_name()
{
	return name_; 
}

Sock_writer *Client::get_writer()
{
	return writer_; 	
}

Client_listener *Client::get_listener()
{
	return listener_; 
}

Client::~Client()
{
	delete writer_; 
	delete listener_; 
}

