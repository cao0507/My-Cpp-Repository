#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		cout << "cannot seek\n";
	else
		cout << "seek ok\n";
	return 0;
}
