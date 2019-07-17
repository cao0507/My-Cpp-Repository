#ifndef EXERCISE15_05_H_
#define EXERCISE15_05_H_

#include "exercise15_03.h"

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);

	double net_price(std::size_t) const override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& b, double p, 
		std::size_t m, double disc) :
		Quote(b, p), min_qty(m), discount(disc) {  };

double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty)
		return cnt*(1 - discount)*price;
	else
		return cnt*price;
}

#endif  //EXERCISE15_05_H_
