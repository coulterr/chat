#include "headers/client.h"


Client::Client(Communicator *comm)
{
	this -> comm = comm; 
}

void Client::set_name(std::string name)
{
	this -> name = name; 
}

std::string Client::get_name()
{
	return name; 
}

bool Client::send_message(std::string message)
{ 
	return (*comm).send_message(message); 
}

std::string Client::recv_message()
{
	return (*comm).recv_message(); 
}


Client::~Client()
{
}

