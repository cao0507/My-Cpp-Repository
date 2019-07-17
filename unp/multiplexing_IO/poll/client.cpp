#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>

#define DEFAULT_PORT 6666
#define MAXLINE 1024

void handle_connection(int sockfd);

int main(int argc, char **argv) {
	int connfd = 0;
	struct sockaddr_in clientaddr;
	if (argc < 2){
		printf("Usage: client [server IP address]\n");
		return -1;
	}

	clientaddr.sin_family = AF_INET;
	clientaddr.sin_port = htons(DEFAULT_PORT);
	clientaddr.sin_addr.s_addr = inet_addr(argv[1]);
	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if (connfd < 0){
		perror("socket");
		return -1;
	}
	if (connect(connfd, (struct sockaddr*) &clientaddr, sizeof(clientaddr)) < 0){
		perror("connect");
		return -1;
	}

	handle_connection(connfd);
	return 0;
}

void handle_connection(int sockfd) {
	char sendline[MAXLINE], recvline[MAXLINE];
	struct pollfd pfds[2];
	int n;

	pfds[0].fd = sockfd;
	pfds[0].events = POLLIN;

	pfds[1].fd = STDIN_FILENO;
	pfds[1].events = POLLIN;

	while (1) {
		poll(pfds, 2, -1);
		if (pfds[0].revents & POLLIN){
			n = read(sockfd, recvline, MAXLINE);
			if (n == 0){
				fprintf(stderr, "client: server is closed.\n");
				close(sockfd);
			}
			write(STDOUT_FILENO, recvline, n);
		}
		if (pfds[1].revents & POLLIN){
			n = read(STDIN_FILENO, sendline, MAXLINE);
			if (n == 0){
				shutdown(sockfd, SHUT_WR);
				continue;
			}
			write(sockfd, sendline, n);
		}
	}
}
