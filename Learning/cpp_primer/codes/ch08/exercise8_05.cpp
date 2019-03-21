#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main(){
	ifstream infile("ens3.txt", ifstream::in);
	vector<string> vec;
	if (infile){
		string word;
		while (infile >> word){
			vec.push_back(word);
		}
	}

	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << endl;
	}
	return 0;
}
