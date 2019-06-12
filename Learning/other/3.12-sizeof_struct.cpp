#include <iostream>

using namespace std;

//#pragma pack(4)

typedef union{
	long i;
	int k[5];
	char c;
}UDATE;

struct data{
	int cat;
	UDATE cow;
	double dog;
}too;

int func(int x){
	return x;
}

struct C{
	char i;
	struct{
		char c;
		int j;
	} ss;
	short k;
};

class B{
	public:
		virtual void funa();
		virtual void funb();
		void func();
		static void fund();
		static int si;

	private:
		char c;
		int i;
		char c1;
};

int main(){
	//struct A{
		//char i;
		//struct {
			//char c;
			//short j;
		//}ss;
		//long k;
	//};
	//cout << sizeof(A) << endl;
	
	//UDATE temp;
	//cout << sizeof(struct data) << " " << sizeof(temp) << endl;	
	//cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	return 0;
}
