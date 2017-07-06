objects = main.o 

client: $(objects)
	g++ -o client $(objects) -lpthread -std=c++11
main.o: main.cc
	g++ -c -o main.o main.cc -std=c++11
clean: 
	rm client $(objects)
