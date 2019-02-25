#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "usage: a.out <pathname>" << endl;
		return 0;
	}
	if ( access(argv[1], R_OK) < 0 ){
		cerr << "access error for " << argv[1] << endl;
	}
	else
		cout << "read access OK" << endl;

	if ( open(argv[1], O_RDONLY) < 0 ){
		cerr << "open error for " << argv[1] << endl;
	}
	else
		cout << "open for reading OK" << endl;

	return 0;
}
