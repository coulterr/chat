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
#include "client_directory.h"

class Connection
{
	private:
		Client_directory *directory; 
		Client *cli; 
	public:
		Connection(int sockfd, Client_directory *directory);
		bool process_login();
		void listen_for_messages();
		void start();
		~Connection(); 
};
#endif // CONNECTION_H_INCLUDED
