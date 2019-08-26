#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> split(string& str){
	vector<int> res;
	string tmp = "";
	for (int i = 0; i < str.size(); i++){
		if (str[i] == '.'){
			res.push_back(stoi(tmp));
			tmp = "";
		}
		else
			tmp += str[i];
	}
	res.push_back(stoi(tmp));
	return res;
}

int main()
{
	int m;
	cin >> m;
	while (m--){
		string str1, str2;
		cin >> str1 >> str2;
		vector<int> v1 = split(str1);
		vector<int> v2 = split(str2);
		int i;
		bool next = false;
		for (i = 0; i < v1.size() && i < v2.size(); i++){
			if (v1[i] < v2[i]){
				cout << "true" << endl;
				next = true;
				break;
			}
			else if (v1[i] > v2[i]){
				cout << "false" << endl;
				next = true;
				break;
			}
		}
		if (!next && i < v2.size()){
			for (; i < v2.size(); i++){
				if (v2[i] > 0){
					cout << "true" << endl;
					next = true;
					break;
				}
			}
		}
		else if (!next && i < v1.size()){
			for (; i < v1.size(); i++){
				if (v1[i] > 0){
					cout << "false" << endl;
					next = true;
					break;
				}
			}
		}
		if (!next)
			cout << "false" << endl;
	}
	return 0;
}


