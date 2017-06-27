default: 
	g++ -c main.cc -o main.o -std=c++11
	g++ -c client.cc -o client.o -std=c++11
	g++ -c client_entrypoint.cc -o client_entrypoint.o -std=c++11
	g++ -c client_listener.cc -o client_listener.o -std=c++11
	g++ -c sock_reader.cc -o sock_reader.o -std=c++11
	g++ -c sock_writer.cc -o sock_writer.o -std=c++11
	g++ -c sock_server.cc -o sock_server.o -std=c++11
	g++ main.o client.o client_entrypoint.o client_listener.o sock_reader.o sock_writer.o sock_server.o -o server -std=c++11 -lpthread
