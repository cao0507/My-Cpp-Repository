#include <iostream>
#include <iomanip>
#include <sys/stat.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	struct stat buf;
	string ptr;
	for (int i = 1; i < argc; i++){
		cout << left << setw(30) << argv[i] << ": ";
		if ( lstat(argv[i], &buf) < 0 ){
			cerr << left << setw(20) << "lstat error" << endl;
			continue;
		}

		if (S_ISREG(buf.st_mode))
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";
		else
			ptr = "** unknown mode **";

		cout << left << setw(20) << ptr << endl;
	}
	return 0;
}
