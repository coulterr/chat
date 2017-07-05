#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/sock_server.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_dir.h"
//#include "headers/admin_tools.h"
int main()
{
	Client_dir *client_dir = new Client_dir(); 
	Threadpool *tpool = new Threadpool(client_dir); 
	std::thread server_thread = std::thread(listen_on_port, 4486, tpool); 
	//std::thread admin_thread = std::thread(listen_for_admin, tpool, client_dir); 
	//listen_on_port(4449, func); 
	server_thread.join(); 
	return 0; 	
}
