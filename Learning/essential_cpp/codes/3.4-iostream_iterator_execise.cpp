#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>

using namespace std;


int main(){
	ofstream odd_file("./other/odd_file.txt");
	ofstream even_file("./other/even_file.txt");

	if (!odd_file || !even_file){
		cerr << "!! unable to open the necessary files.\n";
		return -1;
	}

	istream_iterator<int> is(cin);
	istream_iterator<int> eof;

	vector<int> all;
    vector<int>	odd;
    vector<int>	even;
	copy(is, eof, back_inserter(all));
	for (auto &v:all){
		if (v%2 != 0)
			odd.push_back(v);
		else
			even.push_back(v);
	}

	ostream_iterator<int> os_odd(odd_file, "\n");
	ostream_iterator<int> os_even(even_file, "\n");
	copy(odd.begin(), odd.end(), os_odd);
	copy(even.begin(), even.end(), os_even);
	return 0;
}
