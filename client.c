#include "common.h"

int main(int count,char*arg[])
{
	pthread_t rThread, sThread;
	int ret, clntSock;
	
	// setup sockets	
	setupClient(arg[1], &clntSock);

	// fire off some threads
	if((ret = pthread_create(&rThread, 
				NULL, 
				receiveMessage_t, 
				(void *) &clntSock)) < 0)
		printf("\n\n\nPROBLEM\n\n\n");
	
	if((ret = pthread_create(&sThread, 
				NULL, 
				sendMessage_t, 
				(void *) &clntSock)) < 0)
		printf("\n\n\nPROBLEM\n\n\n");
	

	pthread_join(rThread, NULL);	
	
	// clean this mess up
	close(clntSock);
	return 0;
}
