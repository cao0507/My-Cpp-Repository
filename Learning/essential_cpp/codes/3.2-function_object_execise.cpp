#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read_file(vector<string> &svec, string filename){
	ifstream infile(filename);
	string str;
	while (infile >> str){
		svec.push_back(str);
	}
}

void sort(vector<string> &svec, bool compare(string, string)){
	for (unsigned long i = 0; i < svec.size()-1; ++i){
		for (unsigned long j = i+1; j < svec.size(); ++j){
			if (compare(svec[j], svec[i])){
				string temp = svec[i];
				svec[i] = svec[j];
				svec[j] = temp;
			}
		}
	}
}

bool compare(string s1, string s2){
	if (s1.size() < s2.size())
		return true;
	else
		return false;
}

void display(vector<string> &svec){
	for (auto it = svec.begin(); it != svec.end(); ++it)
		cout << *it << endl;
}

int main(){
	vector<string> svec;
	string filename = "./other/test.txt";
	read_file(svec, filename);
	display(svec);
	sort(svec, compare);
	display(svec);
	return 0;
}
