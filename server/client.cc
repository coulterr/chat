#include "headers/client.h"

Client::Client(std::string name, SockWriter *writer, ClientListener *listener) 
{
	(*this).name = name; 
	(*this).writer = writer; 
	(*this).listener = listener; 		
}

std::string Client::getName()
{
	return name; 
}

SockWriter *Client::getWriter()
{
	return writer; 	
}

ClientListener *Client::getListener()
{
	return listener; 
}

Client::~Client()
{
	delete writer; 
	delete listener; 
}

