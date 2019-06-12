#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>
#include "heads/dg_cli.h"

using namespace std;

int main(int argc, char **argv){
	int 				sockfd;
	struct sockaddr_in 	servaddr;

	if (argc != 3){
		cerr << "usage: " << argv[0] << " <IPaddress> <listen_port>" << endl;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		cerr << "socket error" << endl;
		return 0;
	}

	dg_cli(stdin, sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	return 0;
}
