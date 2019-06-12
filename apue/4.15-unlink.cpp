#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	if (argc < 2){
		cerr << "usage: ./Unlink filename filename ..." << endl;
		return 0;
	}

	for (int i = 1; i < argc; i++){
		if (open(argv[i], O_RDWR) < 0){
			cerr << "open error" << endl;
			return 0;
		}
		if (unlink(argv[i]) < 0){
			cerr << "unlink error" << endl;
			return 0;
		}
		cout << "file " << argv[i] << " has been unlinked" << endl;
	}
	return 0;
}
