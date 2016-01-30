#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

#define SER_PORT 1200
#define BUF_SIZE 30

void setupServer(int *sersock, int *newsock);
void setupClient(char* servIP, int *sock);
void *receiveMessage_t(void *sock);
void sendMessage(int socket);
void *sendMessage_t(void *sock);

