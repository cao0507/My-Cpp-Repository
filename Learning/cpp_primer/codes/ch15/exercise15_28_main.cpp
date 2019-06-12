#include "exercise15_03.h"
#include "exercise15_05.h"

#include <iostream>
#include <vector>
#include <memory>

int main(){
	std::vector<Quote> v;
	for (unsigned i = 1; i != 3; i++)
		v.push_back(Bulk_quote("sss", i*10, 10, 0.5));

	double total = 0;
	for (const auto &b:v){
		total += b.net_price(20);
	}
	std::cout << total << std::endl;

	std::cout << "======================\n\n";

	std::vector<std::shared_ptr<Quote>> vp;
	for (unsigned i = 1; i != 3; i++)
		vp.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i*10, 10, 0.5)));

	total = 0;
	for (const auto &p:vp)
		total += p->net_price(20);
	std::cout << total << std::endl;

	return 0;
}
