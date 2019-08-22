#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
	int N, M;
	
	vector<string> res;
	while(cin >> N >> M){
		unordered_map<string, string> hashMap;
		while (N--){
			string cmd, action;
			cin >> cmd >> action;
			hashMap[cmd] = action;
		}
		while (M--){
			string cmd;
			cin >> cmd;
			res.push_back(hashMap[cmd]);
		}
	}

	for (auto str:res){
		cout << str << endl;
	}
	return 0;
}
