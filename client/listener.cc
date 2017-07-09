#include "headers/listener.h"

void Listener::process_message(std::string message)
{
	std::cout << message << std::endl; 
}

void Listener::listen_for_messages()
{
	std::string message; 

	while(true)
	{
		message = (*comm).recv_message();  	
		std::cout << message << std::endl; 
	}
}

Listener::Listener(Communicator *comm)
{
	this -> comm = comm;  
}

void Listener::start_listening()
{
	thread = new std::thread(&Listener::listen_for_messages, this); 		
}

Listener::~Listener()
{

}

