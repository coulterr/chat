#ifndef CLIENT_LISTENER_H_INCLUDED
#define CLIENT_LISTENER_H_INCLUDED


#include <iostream>
#include <thread>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include "../headers/sock_reader.h"

class ClientListener 
{
	private:
		SockReader *reader; 
		std::thread *task; 
	public:
		ClientListener(SockReader *reader);
		void listenForMessages();
		void startListening();
		~ClientListener();
};

#endif // CLIENT_LISTENER_H_INCLUDED
