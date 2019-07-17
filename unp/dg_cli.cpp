#include <iostream>
#include <cstring>
#include "heads/dg_cli.h"

#define MAXLINE 	4096

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen){
	int 			n;
	char 			sendline[MAXLINE], recvline[MAXLINE+1];

	while (fgets(sendline, MAXLINE, fp) != NULL){
		if (sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen) < 0){
			std::cerr << "sendto error" << std::endl;
			return;
		}

		if ( (n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL)) < 0 ){
			std::cerr << "recvfrom error" << std::endl;
			return;
		}
		recvline[n] = 0;
		fputs(recvline, stdout);
	}

}
