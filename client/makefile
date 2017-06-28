objects = client.o 

client: $(objects)
	g++ -o client $(objects) -lpthread -std=c++11
client.o: client.cc
	g++ -c -o client.o client.cc -std=c++11
clean: 
	rm client $(objects)
