#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

using namespace std;

int main(){
	umask(0);
	if (creat("foo", RWRWRW) < 0){
		cerr << "creat error for foo" << endl;
		return 0;
	}
	else
		cout << "creat successfully for foo" << endl;

	umask( S_IRGRP | S_IWGRP | S_IROTH |S_IWOTH );
	if (creat("bar", RWRWRW) < 0){
		cerr << "creat error for bar" << endl;
		return 0;
	}
	else
		cout << "creat successfully for bar" << endl;
	return 0;
}
