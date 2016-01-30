all: client server
	
client: client.c
	gcc -o client.exe client.c common.c -pthread

server: server.c
	gcc -o server.exe server.c common.c -pthread	
