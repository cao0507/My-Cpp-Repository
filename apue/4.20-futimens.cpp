#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv){
	if (argc < 2){
		cerr << "usage: ./futimens file" << endl;
		return 0;
	}

	int fd;
	struct stat statbuf;
	struct timespec times[2];
	for (int i = 1; i < argc; i++){
		if (stat(argv[i], &statbuf) < 0){
			cerr << argv[i] << ": stat error" << endl;
			continue;
		}
		else
			cerr << argv[i] << ": stat OK" << endl;

		if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0){
			cerr << argv[i] << ": open error" << endl;
			continue;
		}
		else
			cerr << argv[i] << ": open OK" << endl;

		times[0] = statbuf.st_atim;
		times[1] = statbuf.st_mtim;
		if (futimens(fd, times) < 0){
			cerr << argv[i] << ": futimens error" << endl;
			continue;
		}
		else
			cerr << argv[i] << ": futimens OK" << endl;
		
		close(fd);
	}
	return 0;
}
