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

void Client::set_user(User *user)
{
	this -> user = user; 	
}

User &Client::get_user()
{
	return *user; 
}

Client::~Client()
{
}

