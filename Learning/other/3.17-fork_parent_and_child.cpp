#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
	int pid;
	int num = 1;
	pid = fork();
	
	if (pid == 0){
		//num++;
		(*(&num))++;
		cout << "in child: num= " << num << " addr= " << &num << endl;
	}
	else if (pid > 0){
		sleep(1);
		cout << "in parent: num= " << num << " addr= " << &num << endl;
	}
	return 0;
}
