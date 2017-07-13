#include "headers/connection.h"

const int Connection::IN_MESSAGE = 0; 
const int Connection::IN_FRIEND_REQUEST = 1;  
const int Connection::IN_FRIEND_REQUEST_RESPONSE = 2;  
const int Connection::OUT_MESSAGE = 3; 
const int Connection::OUT_FRIEND_REQUEST = 4; 
const int Connection::OUT_FRIEND_INFO = 5; 
const int Connection::OUT_FRIEND_UPDATE = 6; 


Connection::Connection(int socketfd, Client_directory &directory, Data_accessor &accessor)
:client(socketfd), directory(directory), accessor(accessor)
{
}



bool Connection::process_login()
{
	std::string name = client.recv_message(); 
	user = accessor.get_user_by_name(name); 
	if(user != NULL) 
	{
		client.set_user(user); 
		return true; 
	}
	return false; 
}

bool Connection::process_friend_request_response(std::string message)
{

}

bool Connection::process_friend_request(std::string message) 
{

}

bool Connection::process_normal_message(std::string message)
{
	int recipient_index = message.find_first_of(":", 0); 
	std::string recipient_str = message.substr(0, recipient_index); 
	int recipient = std::stoi(recipient_str, NULL, 0); 

	std::string message_content = message.substr(recipient_index + 1, message.length()); 

	if((*user).has_friend(recipient))
	{
		int sender = (*user).get_id(); 
		std::string o_message = std::to_string(OUT_MESSAGE) + std::string(":") 
			+ std::to_string(sender) + std::string(":") + message_content; 
		directory.dispatch_message(recipient, o_message); 
		return true;  
	}
	else 
	{
		return false; 	
	}
}

bool Connection::process_message(std::string message) 
{
	int prefix_index = message.find_first_of(":", 0);
	std::string prefix_str = message.substr(0, prefix_index); 

	message = message.substr(prefix_index + 1, message.length());
	
	int prefix = std::stoi(prefix_str, NULL, 0); 

	switch(prefix)
	{
		case IN_MESSAGE : 
			return process_normal_message(message); 
		case IN_FRIEND_REQUEST: 
			return process_friend_request(message); 
		case IN_FRIEND_REQUEST_RESPONSE:
			return process_friend_request_response(message); 
	}

}

void Connection::listen_for_messages() 
{
	while(true)
	{ 
		std::string message = client.recv_message();
		if (message.compare("TIMEOUT") == 0)
		{
			if (!directory.dispatch_message((*user).get_id(), "KEEPALIVE"))
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
			bool success = process_message(message); 
			if(!success)
			{	
				std::string recipient_str = std::to_string((*user).get_id()); 
				std::string err_msg = recipient_str + std::string(": Failure to send message");  
				directory.dispatch_message((*user).get_id(), err_msg); 
			}
		}
	}
}

void Connection::start()
{
	std::string session_type = client.recv_message(); 
	if (session_type.compare("REGISTER") == 0) 
	{
		
	}
	else if (session_type.compare("LOGIN") == 0) 
	{
	
		if (process_login()) 
		{
			directory.add_client((*user).get_id(), client); 
			listen_for_messages(); 
			directory.remove_client((*user).get_id()); 
		}
	}
}

Connection::~Connection(){
	delete user; 	
}; 
