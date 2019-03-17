#include <iostream>
#include <errno.h>
#include <cstring>
#include <cstdlib>

using namespace std;

#define LEN 4

int main(){
	int *pt = (int *)malloc(LEN*(sizeof(int))); /* include in <cstdlib> */
	int *p = pt;
	for (int i = 0; i < LEN; i++){
		p++;
	}	

	*p = 5; /* 内存读写越界了，但是也没出现什么问题啊 */
	cout << strerror(errno) << endl;
	cout << *p << endl;
	return 0;
}
