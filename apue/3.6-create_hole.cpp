#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string>

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

using namespace std;

//char 	buf1[] = "abcdefghij";
//char 	buf2[] = "ABCDEFGHIJ";
string buf1 = "abcdefghij";
string buf2 = "ABCDEFGHIJ";

int main() {
	int fd;

	if ( (fd = creat("file.hole", FILE_MODE)) < 0 ){
		cerr << "create error\n";
		return 0;
	}

	if ( write(fd, buf1.c_str(), 10) != 10){
		cerr << "buf1 write error\n";
		return 0;
	}
	// offset now = 10

	if ( lseek(fd, 16384, SEEK_SET) == -1 ){
		cerr << "lseek error\n";
		return 0;
	}
	// offset now = 16384

	if ( write(fd, buf2.c_str(), 10) != 10 ){
		cerr << "buf2 write error\n";
		return 0;
	}
	// offset now = 16394

	return 0;
}
