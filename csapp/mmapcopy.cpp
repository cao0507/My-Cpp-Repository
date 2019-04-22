#include <cstdio>
#include <cstdlib>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char *argv[]){
	int n, fd;
	void *map;
	struct stat statbuf;

	if (argc != 2){
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0){
		perror("open");
		exit(1);
	}
	if (fstat(fd, &statbuf) != 0){
		perror("fstat");
		exit(1);
	}

	map = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	if (close(fd) < 0){
		perror("close");
		exit(1);
	}
	n = write(STDOUT_FILENO, map, statbuf.st_size);
	if (n != statbuf.st_size){
		perror("write");
		exit(1);
	}

	return 0;
}
