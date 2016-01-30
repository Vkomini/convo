#include "common.h"

void setupServer(int *sersock, int *newsock)
{
	struct sockaddr_in seraddr;
	struct sockaddr_in cliinfo;
	socklen_t csize=sizeof(cliinfo);
	seraddr.sin_family=PF_INET;
	seraddr.sin_port=htons(SER_PORT);
	seraddr.sin_addr.s_addr=htonl(INADDR_ANY);

	printf("Starting server\n");
	if((*sersock=socket(PF_INET,SOCK_STREAM, 0))<0)
	{
		perror("\nsocket()");
		exit(0);
	}
	if(bind(*sersock,(struct sockaddr *)&seraddr,sizeof(seraddr))<0)
	{
		perror("\nbind()");
		exit(0);
	}
	if(listen(*sersock,1)<0)
	{
		perror("\nlisten()");
	}
	if((*newsock=accept(*sersock,(struct sockaddr *)&cliinfo,&csize))<0)
	{
		perror("\nacecpt()");
		exit(0);
	}
	else
	{
		printf("now connected to %s\n",inet_ntoa(cliinfo.sin_addr));
	}
}

void setupClient(char* servIP, int *sock)
{
	struct sockaddr_in servAddr;
	servAddr.sin_port = htons(SER_PORT);
	servAddr.sin_family = PF_INET;
	servAddr.sin_addr.s_addr = inet_addr(servIP);

	if( (*sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("\n SOCKET");
		exit(0);
	}
	if( connect(*sock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0)
	{
		perror("\n CONNECT");
		exit(0);
	}
	printf("\nclient connected to %s", servIP);
}

void *receiveMessage_t(void *sock)
{
	char buffer[BUF_SIZE];
	int socket = *(int *) sock;

	while(strcmp(buffer, "BYE") != 0)
	{
		read(socket, buffer, sizeof(buffer));
		printf("msg: %s\n", buffer);
	}
	pthread_exit(0);
}

void sendMessage(int socket)
{
	char buffer[BUF_SIZE];

	while(strcmp(buffer, "BYE") != 0)
	{
		scanf("%s", buffer);
		write(socket, buffer, sizeof(buffer));
	}
}

void *sendMessage_t(void *sock)
{
	char buffer[BUF_SIZE];
	int socket = *(int *) sock;

	while(strcmp(buffer, "BYE") != 0)
	{
		scanf("%s", buffer);
		write(socket, buffer, sizeof(buffer));
	}
	pthread_exit(0);
}

