#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <set>

using namespace std;

class TextQuery{
public:
	TextQuery(ifstream &infile){
		string line;
		while (infile.getline(line, ))
	}

private:
	vector<string> lines;
	map<string, set<int>> textMap;
};


void runQueries(ifstream &infile){
	TextQuery tq(infile);

	while (true){
		cout << "enter word to look for, or q to quit: ";
		string s;
		if ( !(cin >> s) || s == "q" )
			break;
		print(cout, tq.query(s)) << endl;
	}
}

int main(int argc, char **argv){
	if (argc != 2){
		cerr << "usage: " << argv[0] << "<filename>" << endl;
		return 0;
	}

	ifstream infile(argv[1]);
	if ( !infile ){
		cerr << "read file failed." << endl;
	}
	
	runQueries(infile);
	return 0;
}
