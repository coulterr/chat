objects = main.o sock_server.o threadpool.o client.o client_dir.o

server: $(objects) 
	g++ -o server $(objects) -std=c++11 -lpthread
main.o: main.cc 
	g++ -c -o main.o main.cc -std=c++11
sock_server.o: sock_server.cc headers/sock_server.h
	g++ -c -o sock_server.o sock_server.cc -std=c++11
threadpool.o: threadpool.cc headers/threadpool.h
	g++ -c -o threadpool.o threadpool.cc -std=c++11 
client.o: client.cc headers/client.h
	g++ -c -o client.o client.cc -std=c++11
client_dir.o: client_dir.cc headers/client_dir.h
	g++ -c -o client_dir.o client_dir.cc -std=c++11
clean: 
	rm server $(objects) 
