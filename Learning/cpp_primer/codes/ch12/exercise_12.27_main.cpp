#include <iostream>
#include <string>
#include <fstream>
#include "exercise_12.27.h"

using namespace std;

void runQueries(ifstream &infile){
	TextQuery tq(infile);

	while (true){
		cout << "enter word to look for, or q to quit: ";
		string s;

		if (!(cin >> s) || s == "q")
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(){
	ifstream infile("./exercise_12.27.cpp");
	
	if (!infile){
		cerr << "read file error" << endl;
		return 0;
	}

	runQueries(infile);
	return 0;
}
