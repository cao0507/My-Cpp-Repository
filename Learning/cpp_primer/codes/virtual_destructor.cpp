#include <iostream>

class Base {
public:
	Base() { std::cout << "Base Constructor." << std::endl; }
	virtual ~Base() { std::cout << "Base Destructor." << std::endl; }

	virtual void show() { std::cout << "Base show." << std::endl; }
};

class Derived: public Base {
public:
	Derived() { std::cout << "Derived Constructor." << std::endl; }
	~Derived() { std::cout << "Derived Desctructor." << std::endl; }

	void show() { std::cout << "Derived show." << std::endl; }
};

int main() {
	Base* pBase = new Derived();
	pBase->show();
	delete pBase;
	return 0;
}
