#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>


#define MAXLINE 	4096

using namespace std;

int main(int argc, char **argv){
	int 		sockfd, n;
	char 		recevline[MAXLINE + 1];
	
	// sockaddr_in结构定义在<netinet/in.h>头文件中
	struct sockaddr_in  servaddr;

	if (argc != 3){
		cerr << "usage: " << argv[0] << " <IPaddress> <port>" << endl;
		return 0;
	}

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){		//头文件<sys/socket.h>
		cerr << "socket error" << endl;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));		//定义在<stdio.h>头文件中
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(atoi(argv[2]));		//头文件<arpa/inet.h>

	if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0 ){	//头文件<arpa/inet.h>
		cerr << "inet_pton error for " << argv[1] << endl;
		return 0;
	}

	if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
		cerr << "connect error" << endl;
		return 0;
	}

	while ( (n = read(sockfd, recevline, MAXLINE)) > 0 ){ 	//头文件<unisted.h>
		recevline[n] = 0;
		if ( fputs(recevline, stdout) == EOF ){		//头文件<stdio.h>
			cerr << "fputs error" << endl;
			return 0;
		}
	}
	if ( n < 0 ){
		cerr << "read error" << endl;
		return 0;
	}

	return 0;

}
