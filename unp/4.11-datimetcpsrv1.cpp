#include <iostream>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <cstdio>
#include <arpa/inet.h>
#include <cstdlib>
#include <cerrno>

#define MAXLINE		4096
#define LISTENQ 	1024

using namespace std;


int main(int argc, char **argv){
	int 				listenfd, connfd;
	socklen_t 			len;
	struct sockaddr_in  servaddr, cliaddr;	// sockaddr_in结构定义在<netinet/in.h>头文件中
	char 				buff[MAXLINE];
	time_t 				ticks;

	if (argc != 2){
		cerr << "usage: " << argv[0] << " <listen_port>" << endl;
		return 0;
	}

	if ( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ){
		cerr << "socket error" << endl;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if ( bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ){
		cerr << "bind error" << " "<< strerror(errno) << endl;
		return 0;
	}

	if (listen(listenfd, LISTENQ) < 0){
		cerr << "listen error" << endl;
		return 0;
	}

	for (;;){
		len = sizeof(cliaddr);
		if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &len)) < 0){
			cerr << "accept error" << endl;
			return 0;
		}
		cout << "connection from: " 
			<< inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)) 
			<< " port: " 
			<< ntohs(cliaddr.sin_port)
			<< endl;

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
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
