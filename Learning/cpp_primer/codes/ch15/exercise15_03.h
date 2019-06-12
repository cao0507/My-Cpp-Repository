#ifndef EXERCISE15_3_H_
#define EXERCISE15_3_H_

#include <iostream>
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price) {}

	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const {
		return n*price;
	}

	void debug() const;

private:
	std::string bookNo;

protected:
	double price = 0.0;
};

void Quote::debug() const {
	std::cout << "data members of this class:\n"
			<< "bookNo= " << this->bookNo << " "
			<< "price= " << this->price << std::endl;
}

#endif	//EXERCISE15_3_H_
