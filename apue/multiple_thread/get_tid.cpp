#include <stdio.h>
#include <pthread.h>

void* function(void* args)
{
	printf("thread id in pthread is: %lu\n", pthread_self());
	pthread_exit((void*)1);
}

int main()
{
	pthread_t tid;
	int iRet = pthread_create(&tid, NULL, function, NULL);
	if (iRet){
		printf("pthread_create error");
		return iRet;
	}
	printf("thread id in process is: %lu\n", tid);
	iRet = pthread_join(tid, NULL);
	if (iRet){
		printf("thread_join error");
		return iRet;
	}
	return 0;
}
