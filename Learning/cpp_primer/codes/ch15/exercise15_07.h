#ifndef EXERCISE15_07_H_
#define EXERCISE15_07_H_

#include "exercise15_03.h"
#include <string>

class Limit_quote : public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string&, double, std::size_t, double);

	double net_price(std::size_t) const ;

private:
	std::size_t limits = 0;
	double discount = 0.0;
};

Limit_quote::Limit_quote(const std::string& b, double p, 
		std::size_t lim, double disc) :
		Quote(b, p), limits(lim), discount(disc) 
		{ }

double Limit_quote::net_price(std::size_t n) const {
	if (n < limits)
		return n*(1 - discount)*price;
	else
		return limits*(1- discount)*price + (n - limits)*price;
}

#endif 	//EXERCISE15_07_H_
