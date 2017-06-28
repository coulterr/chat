server: main.o sock_server.o threadpool.o client.o
	g++ -o server main.o sock_server.o threadpool.o client.o -std=c++11 -lpthread
main.o: main.cc
	g++ -c -o main.o main.cc -std=c++11
sock_server.o: sock_server.cc
	g++ -c -o sock_server.o sock_server.cc -std=c++11
threadpool.o: threadpool.cc
	g++ -c -o threadpool.o threadpool.cc -std=c++11 
client.o: client.cc
	g++ -c -o client.o client.cc -std=c++11
clean: 
	rm *.o -f
	rm server
