#ifndef SOCK_SERVER_H_INCLUDED
#define SOCK_SERVER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <functional>
#include <thread>
#include "../headers/threadpool.h"

void client_entrypoint(int sockfd, Threadpool *tpool);
void listen_on_port(int port_num, Threadpool *tpool);

#endif // SOCK_SERVER_H_INCLUDED
