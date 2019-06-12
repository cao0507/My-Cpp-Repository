#include <iostream>
#include <string>
#include <memory>

int main(){
	int n = 5;
	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(n);
	std::string str;
	auto q = p;
	while (std::cin >> str && q != p+n){
		alloc.construct(q++, str);
	}

	while (q != p){
		std::cout << *--q << " ";
		alloc.destroy(q);
	}

	alloc.deallocate(p, n);
	return 0;
}
