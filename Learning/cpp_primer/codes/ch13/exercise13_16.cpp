#include <iostream>

using namespace std;

class numbered{
public:
	numbered() {
		mysn = unique++;
	}

	numbered(const numbered &s){
		mysn = unique++;
	}

	int mysn;

private:
	static int unique;
};

int numbered::unique = 1;

void f (const numbered &s) {
   	cout << s.mysn << endl;
}

int main(){
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;	
}
