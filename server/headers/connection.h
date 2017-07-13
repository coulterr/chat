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
#include "data_accessor.h"
#include "user.h"
class Connection
{
	private: 
		Client client; 
		Client_directory &directory; 
		Data_accessor &accessor; 
		User *user; 
		static const int IN_MESSAGE; 
		static const int IN_FRIEND_REQUEST; 
		static const int IN_FRIEND_REQUEST_RESPONSE; 
		static const int OUT_MESSAGE; 
		static const int OUT_FRIEND_REQUEST; 
		static const int OUT_FRIEND_INFO; 
		static const int OUT_FRIEND_UPDATE; 
	public:
		Connection(int socketfd, Client_directory &directory, Data_accessor &accessor); 
		bool process_friend_request_response(std::string message); 
		bool process_friend_request(std::string message); 
		bool process_normal_message(std::string message); 
		bool process_message(std::string message); 
		bool process_login();
		void listen_for_messages();
		void start();
		~Connection(); 
};
#endif // CONNECTION_H_INCLUDED
