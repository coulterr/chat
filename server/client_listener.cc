#include "headers/client_listener.h"

ClientListener::ClientListener(SockReader *reader)
{
	(*this).reader = reader; 
}

void ClientListener::listenForMessages()
{
	while(true)
	{
		std::string msg = (*reader).recvMsg(); 
		std::cout << msg << std::endl; 
	}
}

//void ClientListener::startListening()
//{
//	task = new std::thread(&ClientListener::listenForMessages, this); 
//}

ClientListener::~ClientListener()
{
	delete task; 
	delete reader; 
}
