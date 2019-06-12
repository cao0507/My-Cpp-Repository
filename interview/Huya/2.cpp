#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string str;
	cin >> str;
	vector<int> nums;
	int begin = 0;
	int flag = 0, sign = 1;
	for (size_t i = 0; i < str.size(); i++){
		if (str[i] == '-' && flag == 0)
			sign = -1;
		else if (str[i] == '-' && flag == 1){
			string temp(str.begin()+begin, str.begin()+i);
			nums.push_back(sign*stoi(temp));
		}
		else if (str[i] < '0' || str[i] > '9'){
			flag = 0;
			sign = 0;
		}
		else if (flag == 0){
			begin = i;
		}
	}

	int sum = 0;
	for (size_t i = 0; i < nums.size(); i++){
		sum += nums[i];
	}
	cout << sum << endl;
	return 0;
}
