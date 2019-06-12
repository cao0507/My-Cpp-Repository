#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
	pid_t pid;
	pid = fork();
	if (pid > 0){
		cout << "Parent, PID: " << getpid() << " Child PID: " << pid << endl;
		int status = -1;
		wait(&status);
		sleep(10);
	}
	else if (pid == 0){
		cout << "Child,  PID: " << getpid() << " Parent PID: " << getppid() << endl;
	}
	return 0;
}
