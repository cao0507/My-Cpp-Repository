#ifndef _DECORATOR_H_
#define _DECORATOR_H_


class Person {
	virtual void show();
};

class Finery : Person {
public:
	Finery() {}
	Finery(Person*);
	void show();

private:
	Person* component;
};

class TShirts : Finery {
	TShirts() {}
	TShirts(Person*) : Finery(Person*) {}
	void show();
};

class BigTrouser : Finery {
	BigTrouser() {}
	BigTrouser(Person*) : Finery(Person*) {}
	void show();
};
