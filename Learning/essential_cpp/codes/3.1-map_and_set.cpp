#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

void read_file(map<string, int> &word_map, ifstream &infile){
	set<string> word_exclusion{"a", "an", "or" "the", "and", "but"};
	string str;
	while (infile >> str){
		if (word_exclusion.find(str) == word_exclusion.end()){
			word_map[str]++;
		}
	}
}

void display_map(map<string, int> &word_map){
	for (auto it = word_map.begin(); it != word_map.end(); ++it)
		cout << "key: " << it->first
			<< "\tvalue: " << it->second << endl;
}

int main(){
	map<string, int> word_map;
	ifstream infile("./other/test.txt");
	read_file(word_map, infile);
	display_map(word_map);
	return 0;
}
