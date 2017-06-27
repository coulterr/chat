#include "headers/sock_server.h"

		
void listen_on_port(int port_num, std::function<void(int)> func)
{
       	int server_fd;
        struct sockaddr_in client_addr, server_addr;
        socklen_t client_len;

        server_fd = socket(AF_INET, SOCK_STREAM, 0);

        if(server_fd < 0)
        {
               	fprintf(stderr, "ERROR: COULD NOT CREATE SERVER SOCKET\n");
               	exit(1);
        }

       	//specify address family
       	server_addr.sin_family = AF_INET;
       	//specify port number
       	server_addr.sin_port = htons(port_num);
       	//Specify address (accept connections of any of machine IP addresses)
       	server_addr.sin_addr.s_addr = INADDR_ANY;

        //bind socket file descriptor to specified local address (IP + port)
        if( bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
        {
               	fprintf(stderr, "ERROR: COULD NOT BIND SERVER SOCKET TO LOCAL IP\n");
               	exit(1);
        }


        //Listen on server socket, up to 300 connection queue
        if( listen(server_fd, 300) == -1)
        {
               	fprintf(stderr, "ERROR: COULD NOT LISTEN ON SERVER SOCKET\n");
               	exit(1);
        }



        client_len = sizeof(client_addr);
        fprintf(stderr, "Listening for clients...\n");

        for(;;)
        {
               	int client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
		std::thread *t = new std::thread(func, client_fd); 
		
        }
}
