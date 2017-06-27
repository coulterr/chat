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
void listenOnPort(int port_num, std::function<void(int)> func);

#endif // SOCK_SERVER_H_INCLUDED
