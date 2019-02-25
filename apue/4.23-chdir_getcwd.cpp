#include <iostream>
#include <unistd.h>
#include <cstdlib>
//#include </home/chl/apue/apue.3e/lib/pathalloc.c>

using namespace std;

int main(int argc, char **argv){
	if (argc != 2){
		cerr << "usage: ./chdir pathname" << endl;
		return 0;
	}

	char *ptr;
	size_t size = 256;

	if (chdir(argv[1]) < 0) {
		cerr << "cd " << argv[1] << " error" << endl;
		return 0;
	}
	else{
		cout << "cd " << argv[1] << " successfully" << endl;
		ptr = (char*)malloc(size);
		if (getcwd(ptr, size) == NULL){
			cerr << "getcwd failed" << endl;
			return 0;
		}
		cout << "cwd = " << ptr << endl;
	}

	return 0;
}
