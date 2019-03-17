#include <iostream>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <errno.h>
#include <signal.h>

#define MAXLINE		4096
#define LISTENQ 	1024


using namespace std;

ssize_t						/* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = (const char*)vptr;
	nleft = n;
	while (nleft > 0) {
		if ( (nwritten = write(fd, ptr, nleft)) <= 0 ) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;		/* and call write() again */
			else
				return(-1);			/* error */
											
		}
		nleft -= nwritten;
		ptr   += nwritten;
												
	}
	return(n);
}
/* end writen */

void str_echo(int sockfd){
	ssize_t 			n;
	char 				buf[MAXLINE];

again:
	while ( (n = read(sockfd, buf, MAXLINE)) > 0){
		if (writen(sockfd, buf, n) < 0){
			cerr << "str_echo: write error" << endl;
			return;
		}
	}
	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0){
		cerr << "str_echo: read error" << endl;
		return;
	}
}

int main(int argc, char **argv){
	int 				listenfd, connfd;
	pid_t 				childpid;
	socklen_t 			len;
	struct sockaddr_in  servaddr, cliaddr;	// sockaddr_in结构定义在<netinet/in.h>头文件中
	char 				buff[MAXLINE];

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
		cerr << "bind error" << endl;
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

		if ( (childpid = fork()) < 0 ){
			cerr << "fork error" << endl;
			return 0;
		}
		else if ( childpid == 0 ){
			if ( close(listenfd) < 0 ){
				cerr << "close listenfd error" << endl;
				return 0;
			}
			str_echo(connfd);
			return 0;
		}
		
		if (close(connfd) < 0){
			cerr << "close connfd error" << endl;
			return 0;
		}
	}

	return 0;
}
