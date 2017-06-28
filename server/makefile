default: 
	g++ -c main.cc -o main.o -std=c++11
	g++ -c client.cc -o client.o -std=c++11
	g++ -c sock_server.cc -o sock_server.o -std=c++11
	g++ -c threadpool.cc -o threadpool.o -std=c++11 
	g++ main.o client.o sock_server.o -o threadpool.o server -std=c++11 -lpthread
