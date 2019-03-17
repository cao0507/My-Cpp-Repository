#include <iostream>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char **argv){
	struct addrinfo *ailist, *aip;
	struct addrinfo hint;
	struct sockaddr_in *sinp;
	const char *addr;
	int err;
	char abuf[INET_ADDRSTRLEN];
	
	if (argc != 3){
		cerr << "usage: " << argv[1] << " nodename service" << endl;
		return 0;
	}
	hint.ai_flags = AI_CANONNAME;
	hint.ai_family = 0;
	hint.ai_socktype = 0;
	hint.ai_protocol = 0;
	hint.ai_addrlen = 0;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;

	if ( (err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0 ){
		cerr << "getaddrinfo error: " << gai_strerror(err) << endl;
		return 0;
	}
	for (aip = ailist; aip != NULL; aip = aip->ai_next){
		if (aip->ai_family == AF_INET){
			sinp = (struct sockaddr_in *)aip->ai_addr;
			addr = inet_ntop(AF_INET, &sinp->sin_addr, abuf, INET_ADDRSTRLEN);
			cout << "address: " << addr << endl;
			cout << "port: " << ntohs(sinp->sin_port) << endl;
		}
	}
}
