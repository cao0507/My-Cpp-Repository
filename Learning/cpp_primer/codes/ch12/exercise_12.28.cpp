#include <iostream>
#include <vector>
using std::vector;

#include <string>
using std::string;
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>


int main(){
	std::ifstream infile("exercise_12.28.cpp");
	vector<string> input;
	std::map<string, std::set<vector<string>::size_type>> dic;
	decltype(input.size()) lineNo(0);

	for (string line; std::getline(infile, line); ++lineNo){
		input.push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()){
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			dic[word].insert(lineNo);
		}
	}

	while (true){
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q")
			break;
		auto found = dic.find(s);
		if (found != dic.end()){
			std::cout << s << " occurs " << found->second.size() << (found->second.size() > 1?"times":"time") << std::endl;
			for (auto i:found->second){
				std::cout << "\t(line " << i+1 << ") " << input[i] << std::endl;
			}
		}
		else{
			std::cout << s << " occurs 0 time" << std::endl;
		}
	}
	return 0;
}
