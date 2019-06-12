#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <cstdlib>
#include "heads/dg_echo.h"

using namespace std;

int main(int argc, char **argv){
	int 				sockfd;
	struct sockaddr_in 	servaddr, cliaddr;
	
	if ( argc != 2 ){
		cerr << "usage: " << argv[0] << " <listen_port>" << endl;
		return 0;
	}

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		cerr << "socket error" << endl;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if( bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ){
		cerr << "bind error" << endl;
		return 0;
	}

	dg_echo( sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr) );

	return 0;
}
