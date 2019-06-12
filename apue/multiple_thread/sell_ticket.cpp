#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int total_ticket_num = 20;

void* sell_ticket(void* args)
{
	int tmp = *(int*) args;
	for (int i = 0; i < 20; i++){
		if (total_ticket_num > 0){
			sleep(1);
			printf("thread %d sell the %dth ticket\n", tmp, 20 - total_ticket_num + 1);
			total_ticket_num--;
		}
	}
	return 0;
}

int main()
{
	int iRet;
	pthread_t tids[4];
	int thread[4];
	thread[0] = 1;
	thread[1] = 2;
	thread[2] = 3;
	thread[3] = 4;
	int i = 0;
	for (i = 0; i < 4; i++){
		iRet = pthread_create(&tids[i], NULL, &sell_ticket, &thread[i]);
		sleep(i*0.1);
		if (iRet){
			printf("pthread_create error");
			return iRet;
		}
	}

	sleep(20);
	//void *retval;
	for (i = 0; i < 4; i++){
		iRet = pthread_join(tids[i], NULL);
		if (iRet){
			printf("pthread_join error");
			return iRet;
		}
	}
	return 0;
}
