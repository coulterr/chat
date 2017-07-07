#include "headers/connection.h"

Connection::Connection(int sockfd, Client_dir *directory)
{
	this -> cli = new Client(sockfd); 
	this -> directory = directory; 
}

bool Connection::process_login()
{
	std::string name = (*cli).recv_msg(); 
	(*cli).set_name(name); 
	return true; 
}

void Connection::listen_for_messages() 
{
	while(true)
	{ 
		std::cout << "Receiving from: " << (*cli).get_name() << std::endl; 
		std::string msg = (*cli).recv_msg();
		if (msg.compare("TIMEOUT") == 0)
		{
			if (!(*directory).dispatch_msg((*cli).get_name(), "KEEPALIVE"))
			{
				std::cout << "DIRTY SHUTDOWN" << std::endl;
				break;  
			}
		}
		else if (msg.compare("ERROR") == 0)
		{
			std::cout << "CLIENT LOST" << std::endl; 
			break; 
		}	
		else if (msg.compare("CLOSED") == 0)
		{
			std::cout << "CLEAN EXIT" << std::endl; 
			break; 	
		}
		else {
			std::string recipient = msg.substr(0, msg.find_first_of(" ", 0));
			msg = msg.substr(msg.find_first_of(" ", 0), msg.length());  
			msg = (*cli).get_name() + ": " + msg;
			(*directory).dispatch_msg(recipient, msg); 
		}
	}
}

void Connection::start()
{	
	if ((*this).process_login()) 
	{
		(*directory).add_client(cli); 
		(*this).listen_for_messages(); 
		//clean and remove
		(*directory).remove_client((*cli).get_name()); 
		delete cli; 

	}
}


Connection::~Connection()
{

}
