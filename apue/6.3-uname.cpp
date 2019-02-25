#include <iostream>
#include <sys/utsname.h>
#include <iomanip>

using namespace std;

int main(){
	//struct utsname uts_name;
	utsname uts_name;
	if ( uname(&uts_name) < 0 ){
		cerr << "uname error" << endl;
		return 0;
	}
	cout << left << setw(35) << "name of the OS: " << left << setw(30) <<  uts_name.sysname << endl;
	cout << left << setw(35) << "name of this node: " << left << setw(30) <<  uts_name.nodename << endl;
	cout << left << setw(35) << "current release of OS: " << left << setw(30) <<  uts_name.release << endl;
	cout << left << setw(35) << "current version of this release: " << left << setw(30) <<  uts_name.version << endl;
	cout << left << setw(35) << "name of hardware type: " << left << setw(30) <<  uts_name.machine << endl;
	cout << left << setw(35) << "name of domainname: " << left << setw(30) <<  uts_name.domainname << endl;

	return 0;
}
