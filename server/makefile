objects = main.o server_thread.o threadpool.o client.o client_directory.o connection.o admin_thread.o communicator.o 

server: $(objects) 
	g++ -o server $(objects) -std=c++11 -lpthread
main.o: main.cc 
	g++ -c -o main.o main.cc -std=c++11
server_thread.o: server_thread.cc headers/server_thread.h
	g++ -c -o server_thread.o server_thread.cc -std=c++11
threadpool.o: threadpool.cc headers/threadpool.h
	g++ -c -o threadpool.o threadpool.cc -std=c++11 
client.o: client.cc headers/client.h
	g++ -c -o client.o client.cc -std=c++11
client_directory.o: client_directory.cc headers/client_directory.h
	g++ -c -o client_directory.o client_directory.cc -std=c++11
connection.o: connection.cc headers/connection.h
	g++ -c -o connection.o connection.cc -std=c++11
admin_thread.o: admin_thread.cc headers/admin_thread.h
	g++ -c -o admin_thread.o admin_thread.cc -std=c++11
communicator.o: communicator.cc headers/communicator.h
	g++ -c -o communicator.o communicator.cc -std=c++11
clean: 
	rm server $(objects) 



dbtest: dbtest.o data_accessor.o sqlite3.o

dbtest.o: dbtest.cc
	g++ -c -o dbtest.o dbtest.cc -std=c++11
data_accessor.o: data_accessor.cc headers/data_accessor.h
	g++ -c -o data_accessor.o data_accessor.cc -std=c++11 
user.o: user.cc headers/user.h
	g++ -c -o user.o user.cc -std=c++11
sqlite3.o: sqlite3.c headers/sqlite3.h
	gcc -c -o sqlite3.o sqlite3.c 
dbtest: 
	g++ -o dbtest dbtest.o data_accessor.o sqlite3.o -std=c++11 -lpthread -ldl
clean_dbtest:
	rm dbtest dbtest.o data_accessor.o sqlite3.o 
