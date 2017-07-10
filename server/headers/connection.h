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

class Connection
{
	public:
		static bool process_login(Client &client, Client_directory &directory);
		static void listen_for_messages(Client &client, Client_directory &directory);
		static void start(Client &client, Client_directory &directory);
};
#endif // CONNECTION_H_INCLUDED
