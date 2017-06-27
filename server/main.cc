#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>

#include "headers/sock_server.h"
#include "headers/client_entrypoint.h"

using std::thread; 


int say_hello(int client_fd)
{
	send(client_fd, "Hello!", 6,  0); 
	close(client_fd); 	
}

int main()
{
	std::function<void(int)> func = clientEntrypoint; 
	//std::thread comm_thread (listen_on_port, 4447, std::ref(func)); 		
	//comm_thread.join(); 	
	listenOnPort(4449, func); 
	return 0; 	
}
