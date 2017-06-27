#include "headers/client_entrypoint.h"


void clientEntrypoint(int sock_fd)
{
	SockReader *reader = new SockReader(sock_fd); 
	SockWriter *writer = new SockWriter(sock_fd); 

	ClientListener *listener = new ClientListener(reader); 
	

	//Client *cli = new Client(name, writer, listener); 
	//ClientDirSingleton.get_singleton().add_to_dir(cli); 

	(*listener).listenForMessages(); 
}
