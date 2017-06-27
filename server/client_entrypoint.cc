#include "headers/client_entrypoint.h"


void client_entrypoint(int sock_fd)
{
	Sock_reader *reader = new Sock_reader(sock_fd); 
	Sock_writer *writer = new Sock_writer(sock_fd); 

	Client_listener *listener = new Client_listener(reader); 
	

	//Client *cli = new Client(name, writer, listener); 
	//ClientDirSingleton.get_singleton().add_to_dir(cli); 

	(*listener).listen_for_messages(); 
}
