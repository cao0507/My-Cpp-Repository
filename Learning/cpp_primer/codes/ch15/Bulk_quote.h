#ifndef BULK_QUOTE_H_
#define BULK_QUOTE_H_

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string& b, double p, std::size_t n, double disc):
		Disc_quote(b, p, n, disc) {  }

	double net_price(std::size_t n) const override {
		return n*price*( n > quantity ? (1 - discount) : 1 );
	}
};

#endif 	//BULK_QUOTE_H_
