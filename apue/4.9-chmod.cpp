#include <iostream>
#include <sys/stat.h>

using namespace std;

int main(){
	struct stat statbuf;
	if (stat("foo", &statbuf) < 0){
		cerr << "stat error for foo" << endl;
		return 0;
	}

	if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0){
		cerr << "chmod error for foo" << endl;
		return 0;
	}

	if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0){
		cerr << "chmod error for bar" << endl;
		return 0;
	}
	return 0;
}
