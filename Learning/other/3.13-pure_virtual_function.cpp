#include <iostream>

using namespace std;

class Base{
	public:
		virtual void get() = 0;
};

class Derive1:public Base{
	virtual void get() { cout << "this is Derive1\n"; }
};

class Derive2:public Base{
	virtual void get() { cout << "this is Derive2\n"; }
};

int main(){
	Base *p;
	Derive1 d1;
	Derive2 d2;
	p = &d1;
	p->get();
	p = &d2;
	p->get();
	return 0;
}
