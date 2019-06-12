#include <iostream>
#include <vector>
#include <map>

using namespace std;

void display(map<string, vector<string>> &family, string key){
	if (family.find(key) == family.end()){
		cout << "没有该家族！";
		return;
	}
	else{
		vector<string> values = family[key];
		cout << "您查询的家族有以下人口：" << endl;
		for (auto &v:values){
			cout << key + v << "\t";
		}
		cout << endl;
	}
}



int main(){
	map<string, vector<string>> family = {
		{"cao", {"huilong", "yuandong", "mengqi"}},
		{"ding", {"huibing", "dingding"}},
		{"zhu", {"yangyang","zhou"}}
	};
	string Xing;
	cout << "请输入你要查询的家族：" << endl;
	cin >> Xing;
	display(family, Xing);
	return 0;
}
