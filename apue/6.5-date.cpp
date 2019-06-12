#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>

using namespace std;

int main(){
	time_t calptr;
	struct tm *tm;
	char line[4096];

	if (time(&calptr) < 0){
		cerr << "get date error" << endl;
		return 0;
	}

	cout << "the second since 1970.01.01 is: " << calptr << endl;

	tm = localtime(&calptr);

	strftime(line, 4096, "%a %b %d %X %Z %Y\n", tm);
	fputs(line, stdout);
	return 0;
}
