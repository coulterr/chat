#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#include <iostream>
#include <string>
#include <queue>
#include <thread> 
#include <vector>

#include <semaphore.h>
#include <sys/socket.h>

#include "client.h"
#include "communicator.h"
#include "client_directory.h"
#include "Data_accessor.h"

class Connection
{
	private: 
		Client client; 
		Client_directory &directory; 
		Data_accessor &accessor; 
	public:
		Connection(int socketfd, Client_directory &directory, Data_accessor &accessor); 
		bool process_login();
		void listen_for_messages();
		void start();
		~Connection(); 
};
#endif // CONNECTION_H_INCLUDED
