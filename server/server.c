/*
Author: 	Gaurav Arora
Roll No.: 	MT2019038
Date: 		02/10/2019
*/

#include "action.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

int main(){

	signal(SIGTSTP, sigstop_sigkill_handler);
	signal(SIGINT, sigstop_sigkill_handler);
	signal(SIGQUIT, sigstop_sigkill_handler);
	printf("Server Has Started\n");

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd==-1) {
		printf("socket creation failed\n");
		exit(0);
	}
	int optval = 1;
	int optlen = sizeof(optval);
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval, optlen)==-1){
		printf("set socket options failed\n");
		exit(0);
	}
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = htonl(INADDR_ANY);
	sa.sin_port = htons(PORT);

	if(bind(sockfd, (struct sockaddr *)&sa, sizeof(sa))==-1){
		printf("binding port failed\n");
		exit(0);
	}
	if(listen(sockfd, 100)==-1){
		printf("listen failed\n");
		exit(0);
	}
	while(1){
		int connectedfd;
		if((connectedfd = accept(sockfd, (struct sockaddr *)NULL, NULL))==-1){
			printf("connection error\n");
			exit(0);
		}
		pthread_t cli;
		if(fork()==0)
			service_cli(connectedfd);
	}

	close(sockfd);
	return 0;
}
