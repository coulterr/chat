#ifndef CONNECTION_H_INCLUDED
#define CONNECTION_H_INCLUDED

#include <sys/socket.h>
#include <iostream>
#include <string>
#include <queue>
#include <thread> 
#include <vector>
#include <semaphore.h>

#include "../headers/client.h"
#include "../headers/client_dir.h"

class Connection
{
	private:
		Client_dir *directory; 
		Client *cli; 
	public:
		Connection(int sockfd, Client_dir *directory);
		bool process_login();
		void listen_for_messages();
		void start();
		~Connection(); 
};
#endif // CONNECTION_H_INCLUDED
