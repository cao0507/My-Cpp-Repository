#ifndef DISC_QUOTE_H_
#define DISC_QUOTE_H_

#include "exercise15_03.h"

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& b, double p, std::size_t n, double disc) :
		Quote(b, p), quantity(n), discount(disc) {}

	virtual double net_price(std::size_t n) const override = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

#endif 	//DISC_QUOTE_H_
