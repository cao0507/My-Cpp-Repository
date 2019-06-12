#include <iostream>
#include <bitset>
#include <string>

int main(){
	std::bitset<64> b1(32);
	std::bitset<32> b2(1010101);
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b2.to_ulong() <<std::endl;
	return 0;
}
