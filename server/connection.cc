#include "headers/connection.h"

Connection::Connection(int socketfd, Client_directory *directory)
{
	this -> comm = new Communicator(socketfd); 
	this -> client = new Client(comm); 
	this -> directory = directory; 
}

bool Connection::process_login()
{
	std::string name = (*client).recv_message(); 
	(*client).set_name(name); 
	return true; 
}

void Connection::listen_for_messages() 
{
	while(true)
	{ 
		std::string message = (*client).recv_message();
		if (message.compare("TIMEOUT") == 0)
		{
			if (!(*directory).dispatch_message((*client).get_name(), "KEEPALIVE"))
			{
				//std::cout << "DIRTY SHUTDOWN" << std::endl;
				break;  
			}
		}
		else if (message.compare("ERROR") == 0)
		{
			//std::cout << "CLIENT LOST" << std::endl; 
			break; 
		}	
		else if (message.compare("CLOSED") == 0)
		{
			//std::cout << "CLEAN EXIT" << std::endl; 
			break; 	
		}
		else {
			std::string recipient = message.substr(0, message.find_first_of(" ", 0));
			message = message.substr(message.find_first_of(" ", 0), message.length());  
			message = (*client).get_name() + ": " + message;
			(*directory).dispatch_message(recipient, message); 
		}
	}
}

void Connection::start()
{
	std::string session_type = (*client).recv_message(); 
	if (session_type.compare("REGISTER") == 0) 
	{
		
	}
	else if (session_type.compare("LOGIN") == 0) 
	{
	
		if ((*this).process_login()) 
		{
			(*directory).add_client(client); 
			(*this).listen_for_messages(); 
			(*directory).remove_client((*client).get_name()); 
		}
	}

	delete client; 
	delete comm; 
}


Connection::~Connection()
{
	
}
