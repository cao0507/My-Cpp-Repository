#include <iostream>
#include <sys/socket.h>
#include "heads/dg_echo.h"

#define MAXLINE 	4096	

void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen){
	int 			n;
	socklen_t 		len;
	char 			mesg[MAXLINE];
	for (;;){
		len = clilen;
		if ( (n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len)) < 0 ){
			std::cerr << "recvfrom error" << std::endl;
			return;
		}

		if ( sendto(sockfd, mesg, n, 0, pcliaddr, len) < 0 ){
			std::cerr << "sendto error" << std::endl;
			return;
		}
	}
}
