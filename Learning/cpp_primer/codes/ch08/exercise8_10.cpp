#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	ifstream infile("personInfo.txt", ifstream::in);
	vector<string> vec;
	if (infile){
		string line;
		while (getline(infile, line))
			vec.push_back(line);
	}

	for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter){
		istringstream record(*iter);
		string word;
		while (record >> word){
			cout << word << " ";
		}
		cout << endl;
	}
	return 0;
}
