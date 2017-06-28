objects = client.o 

client: $(objects)
	g++ -o client $(objects)
client.o: client.cc
	g++ -c -o client.o client.cc
clean: 
	rm client $(objects)
