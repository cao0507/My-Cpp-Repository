#include <iostream>
#include <memory>

using namespace std;

class parent;
class child;

class parent {
public:
	~parent() { std::cout << "Parent Destructor" << endl; }
	shared_ptr<child> child_ptr;
};

class child {
public:
	~child() { cout << "Child Destructor" << endl; }
	shared_ptr<parent> parent_ptr;
};

int main() {
	shared_ptr<parent> p(new parent());
	shared_ptr<child> c(new child);

	cout << p.use_count() << endl;
	cout << p->child_ptr.use_count() << endl;

	cout << c.use_count() << endl;
	cout << c->parent_ptr.use_count() << endl;

	p->child_ptr = c;
	c->parent_ptr = p;

	cout << p.use_count() << endl;
	cout << p->child_ptr.use_count() << endl;

	cout << c.use_count() << endl;
	cout << c->parent_ptr.use_count() << endl;

	return 0;
}
