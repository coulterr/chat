#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <thread>
#include <functional> 

#include "headers/server_thread.h"
#include "headers/threadpool.h"
#include "headers/client.h"
#include "headers/client_directory.h"
#include "headers/admin_thread.h"
#include "headers/data_accessor.h"
int main()
{
	const int PORT = 4447;
	const int THREADCOUNT = 100; 
	
	Data_accessor *accessor = new Data_accessor(std::string("database.db")); 
	Client_directory *directory = new Client_directory(); 
	Threadpool *threadpool = new Threadpool(THREADCOUNT); 
	Server_thread server_thread(PORT, *threadpool, *directory, *accessor); 
	server_thread.start();
	Admin_thread admin_thread(*threadpool, *directory); 
	admin_thread.start(); 
	std::cout << "Server running..." << std::endl; 



	while(true){}; 
	return 0; 	
}
