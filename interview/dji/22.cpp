#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){
	int N, M;
	vector<string> res;
	while (cin >> N){
		cin >> M;
		map<string, string> str_map;
		while (N--){
			string cmd, action;
			cin >> cmd >> action;
			str_map[cmd] = action;
		}
		while (M--){
			string cmd;
			cin >> cmd;
			res.push_back(str_map[cmd]);
		}
	}

	for (auto str:res){
		cout << str << endl;
	}
	return 0;
}
