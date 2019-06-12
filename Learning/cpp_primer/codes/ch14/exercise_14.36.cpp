#include <iostream>
#include <vector>
#include <string>

class GetInput{
public:
	GetInput(std::istream &i = std::cin) : is(i) {}
	std::string operator() () const
	{
		std::string str;
		std::getline(is, str);
		return is ? str : std::string();
	}

private:
	std::istream &is;
};

int main(){
	GetInput getInput;
	std::vector<std::string> strs;
	while(true){
		std::string str = getInput();
		if (str == "")
			break;
		strs.push_back(str);
	}
	for (auto &str:strs)
		std::cout << str << std::endl;
	return 0;
}
