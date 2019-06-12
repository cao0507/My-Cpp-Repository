#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	vector<string> vec;
	string str;
	ifstream infile("test.txt");
	if (!infile){
		cerr << "Open file test.txt failed." << endl;
	}
	else{
		while (infile >> str){
			vec.push_back(str);	
		}
	}
	//cout << "......" << endl;

	for (auto &v:vec)
		cout << v << " ";

	sort(vec.begin(), vec.end());
	ofstream outfile("output.txt");
	if (!outfile){
		cerr << "Write file output.txt failed." << endl;
	}
	else{
		for (auto &v:vec)
			outfile << v << " ";
	}
	return 0;
}
