#include "headers/client.h"


Client::Client(int socketfd)
: comm(socketfd)
{
}

bool Client::send_message(std::string message)
{ 
	return comm.send_message(message); 
}

std::string Client::recv_message()
{
	return comm.recv_message(); 
}


Client::~Client()
{
}

