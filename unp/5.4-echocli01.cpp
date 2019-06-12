#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <errno.h>


#define MAXLINE 	4096

using namespace std;

/* PAINFULLY SLOW VERSION -- example only */
ssize_t
readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t	n, rc;
	char	c, *ptr;
	ptr = (char*)vptr;
	for (n = 1; n < maxlen; n++) {
	again:
		if ( (rc = read(fd, &c, 1)) == 1 ) {
			*ptr++ = c;
			if (c == '\n')
				break;	/* newline is stored, like fgets() */
		} else if (rc == 0) {
			*ptr = 0;
			return(n - 1);	/* EOF, n - 1 bytes were read */
		} else {
			if (errno == EINTR)
				goto again;
				return(-1);		/* error, errno set by read() */											
		}
	}
	*ptr = 0;	/* null terminate like fgets() */
	return(n);

}
/* end readline */

ssize_t
Readline(int fd, void *ptr, size_t maxlen)
{
		ssize_t		n;

		if ( (n = readline(fd, ptr, maxlen)) < 0 ){
			cerr << "Readline: readline error" << endl;
			return 0;
		}
				return(n);

}

void str_cli(FILE *fp, int sockfd){
	char 		sendline[MAXLINE], recevline[MAXLINE];
	while (fgets(sendline, MAXLINE, fp) != NULL){
		if (write(sockfd, sendline, strlen(sendline)) < 0){
			cerr << "str_cli: write error" << endl;
			return;
		}
		if (Readline(sockfd, recevline, MAXLINE) == 0){
			cerr << "str_cli: server terminated prematurely" << endl;
			return;
		}
		fputs(recevline, stdout);
	}
}

int main(int argc, char **argv){
	int 		sockfd;
	
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

	str_cli(stdin, sockfd);

	return 0;

}
