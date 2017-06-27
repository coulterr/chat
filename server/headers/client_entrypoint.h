#ifndef CLIENT_ENTRYPOINT_H_INCLUDED
#define CLIENT_ENTRYPOINT_H_INCLUDED

#include <string>
#include "../headers/sock_reader.h"
#include "../headers/sock_writer.h"
#include "../headers/client_listener.h"
#include "../headers/client.h"
//#include "../headers/client_dir.h"
//#include "../headers/client_dir_singleton.h"

void clientEntrypoint(int sock_fd);


#endif // CLIENT_ENTRYPOINT_H_INCLUDED
