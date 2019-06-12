#include <iostream>
#include <vector>
#include <string>

using namespace std;

string repair(string &str){
	string res;
	if (str.size() <= 2)
		return str;
	res += str[0];
	res += str[1];
	for (unsigned i = 2; i < str.size(); i++){
		int len = res.size();
		if (str[i] != res[len-1]){
			res += str[i];
			continue;
		}
		else if (res[len-1] == res[len-2])
			continue;
		else if (len > 2 && res[len-2] == res[len-3])
			continue;
		else
			res += str[i];
	}	
	return res;	
}

int main(){
	int N;
	cin >> N;

	string line;
	vector<string> strs;
	for (int i = 0; i < N; i++){
		cin >> line;
		string temp;
		temp = repair(line);
		strs.push_back(temp);
	}

	for (int i = 0; i < N; i++)
		cout << strs[i] << endl;
	return 0;
}
