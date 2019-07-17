#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_t ntid;

void printids(const char *s){
	pid_t	     pid;
	pthread_t    tid;
	pid = getpid();
	tid = pthread_self();

	cout << s << " pid " << pid << " tid " << tid << endl;
}

void *thr_fn(void *arg){
	printids("new thread: ");
	return ((void *) 0);
}

int main(){
	int err;
	err = pthread_create( &ntid, NULL, thr_fn, NULL );
	if (err != 0){
		cerr << "can't create thread" << endl;
		return 0;
	}
	printids("main thread: ");
	sleep(1);
	return 0;
}
