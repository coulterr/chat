#ifndef CLIENT_LISTENER_H_INCLUDED
#define CLIENT_LISTENER_H_INCLUDED


#include <iostream>
#include <thread>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include "../headers/sock_reader.h"

class Client_listener 
{
	private:
		Sock_reader *reader_; 
	public:
		Client_listener(Sock_reader *reader_);
		void listen_for_messages();
		~Client_listener();
};

#endif // CLIENT_LISTENER_H_INCLUDED
