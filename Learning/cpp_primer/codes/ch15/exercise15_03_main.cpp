#include "exercise15_03.h"
#include <iostream>

double print_total( std::ostream &os, const Quote &item, size_t n ){
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

int main(){
	//std::string bookNo = "90002332523";
	//Quote item(bookNo, 56.80);
	char const *s = "9000234235";
	Quote item(s, 56.80);
	print_total(std::cout, item, 5);
	return 0;
}
