#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


bool isLegal(string &line){
	for (auto c:line){
		if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
			return false;
	}
	return true;
}

string shift(string &str){
	string res;
	int len = str.size();
	int time = 10;
	if (len <= 10)
		time = 10%len;
	string s1(str.begin(), str.begin()+time);
	string s2(str.begin()+time, str.end());
	res = s2+s1;
	return res;
}


int main(){
	set<string> legal_strs_set;

	vector<string> legal_strs;
	vector<string> illegal_strs;
	vector<string> shift_strs;
	set<string> ordered_shift_strs;

	string line;
	while (getline(cin, line)){
		if (line == "")
			break;
		if (isLegal(line)){
			if (legal_strs_set.find(line) == legal_strs_set.end()){
				legal_strs.push_back(line);
				legal_strs_set.insert(line);
			}
			
		}
		else
			illegal_strs.push_back(line);
	}
	
	for (auto str:legal_strs){
		string tmp = shift(str);
		shift_strs.push_back(tmp);
		ordered_shift_strs.insert(tmp);
	}

	for (auto str:legal_strs)
		cout << str << " ";
	cout << endl;

	for (auto str:illegal_strs)
		cout << str << " ";
	cout << endl;

	for (auto str:shift_strs)
		cout << str << " ";
	cout << endl;

	for (auto str:ordered_shift_strs)
		cout << str << " ";
	cout << endl;

	return 0;
}
