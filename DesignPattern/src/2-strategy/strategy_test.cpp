#include "2-strategy.h"
#include <string>
#include <iostream>

int main() {
	std::string type, number;
	while (1){
		std::cout << "Please input the discount type: (normal || rebate || return)" << std::endl;
		std::getline(std::cin, type);
		std::cout << "Please inpute the discount number: " << std::endl;
		std::getline(std::cin, number);

		CashContext* cc = new CashContext(type, number);
		cc->GetResult(1000);
	}

	return 0;
}
