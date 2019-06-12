#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 3){
		cerr << "usage: ./Rename oldname newname" << endl;
		return 0;
	}

	if (rename(argv[1], argv[2]) < 0){
		cerr << "rename error" << endl;
		return 0;
	}
	cout << "rename successfully" << endl;
	return 0;
}
