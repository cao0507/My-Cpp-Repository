#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <sys/utsname.h>
#include <iomanip>

#define MAXLINE		4096
#define LISTENQ 	1024

using namespace std;


int main(int argc, char **argv){
	int 				listenfd, connfd;
	struct sockaddr_in  servaddr;	// sockaddr_in结构定义在<netinet/in.h>头文件中
	char 				buff[MAXLINE];

	if (argc != 2){
		cerr << "usage: " << argv[0] << " <listen_port>" << endl;
		return 0;
	}

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if ( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
		cerr << "socket error" << endl;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if ( bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ){
		cerr << "bind error" << endl;
		return 0;
	}

	if (listen(listenfd, LISTENQ) < 0){
		cerr << "listen error" << endl;
		return 0;
	}

	for (;;){
		if ((connfd = accept(listenfd, (struct sockaddr *) NULL, NULL)) < 0){
			cerr << "accept error" << endl;
			return 0;
		}
		struct utsname uts_name;
		uname(&uts_name);
		snprintf(buff, sizeof(buff), "%s\r\n", uts_name.nodename);
		if ( write(connfd, buff, strlen(buff)) < 0 ){
			cerr << "write error" << endl;
			return 0;
		}
		
		if (close(connfd) < 0){
			cerr << "close error" << endl;
			return 0;
		}
	}

	return 0;
}
