objects = main.o listener.o communicator.o

client: $(objects)
	g++ -o client $(objects) -lpthread -std=c++11
main.o: main.cc
	g++ -c -o main.o main.cc -std=c++11
listener.o: listener.cc
	g++ -c -o listener.o listener.cc -std=c++11
communicator.o: communicator.cc
	g++ -c -o communicator.o communicator.cc -std=c++11

clean: 
	rm client $(objects)
