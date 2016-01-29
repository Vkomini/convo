all: client server
	
client: client.c
	gcc -o client client.c common.h -pthread

server: server.c
	gcc -o server server.c common.h -pthread	
