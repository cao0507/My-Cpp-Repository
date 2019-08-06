#include <iostream>

using namespace std;

class A {
public:
    virtual void func(){
        cout << "A::func()" << endl;
    }
};

class B: public A {
public:
    virtual void func(){
        cout << "B::func()" << endl;
    }
};

int main()
{
    A a;
    a.func();
    B b;
    b.func();
    return 0;
}
