#include "exercise15_03.h"
#include "exercise15_05.h"
#include "exercise15_07.h"

#include <iostream>
#include <string>

using namespace std;

double print_total(ostream& os,
		const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << endl;
	return ret;
}

void print_debug(const Quote &item){
	item.debug();
}

int main(){
	// ex15.6
	Quote q("textbook1", 10.60);
	Bulk_quote bq("textbook2", 20.60, 10, 0.3);
	Limit_quote lq("textbook3", 30.60, 10, 0.3);

	print_debug(q);
	print_total(cout, q, 8);
	print_debug(bq);
	print_total(cout, bq, 8);
	print_debug(lq);
	print_total(cout, lq, 8);

	return 0;
}
