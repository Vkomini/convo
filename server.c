#include "common.h"
#include <errno.h>
int main()
{
	pthread_t rThread, sThread;
	int ret, sersock, newsock;
	// setup sockets
	setupServer(&sersock, &newsock);
	
	// fire off the thread
	if((ret = pthread_create(&rThread, 
				NULL, 
				receiveMessage_t, 
				(void *) &newsock)) < 0);
		printf("\n\n\nPROBLEM\n\n\n");
	
	if((ret = pthread_create(&sThread, 
				NULL, 
				sendMessage_t, 
				(void *) &newsock)) < 0);
		printf("\n\n\nPROBLEM\n\n\n");
	
	pthread_join(rThread, NULL);

	// close sockets	
	close(newsock);
	close(sersock);
	return 0;
}
