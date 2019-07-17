#include <sys/socket.h>
#include <cstdio>

void dg_cli(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen);
