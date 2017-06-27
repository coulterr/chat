#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <string>
#include "../headers/client_listener.h"
#include "../headers/sock_writer.h"

class Client
{
	private:
		std::string name; 
		SockWriter *writer; 
		ClientListener *listener; 

	public:
		Client(std::string name, SockWriter *writer, ClientListener *listener);
		std::string getName();
		SockWriter *getWriter();
		ClientListener *getListener();
		~Client();
};
#endif // CLIENT_H_INCLUDED
