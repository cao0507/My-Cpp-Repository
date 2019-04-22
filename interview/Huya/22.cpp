#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main(){
	string str;
	cin >> str;
	size_t i, j;
	int sign = 1;
	vector<int> nums;
	for (i = 0, j = 0; i < str.size() && j < str.size(); ){
		if (str[j] < '0' || str[j] > '9'){
			if (i != j){
				string temp(str.begin()+i, str.begin()+j);
				nums.push_back(sign*stoi(temp));
				i = j;
			}
			else if (str[j] == '-'){
				sign = -1;
				j++;
				i++;
			}
			else{
				sign = 1;
				i++;
				j++;
			}
		}
		else{
			j++;
		}
	}

	if (i != j){
		string temp(str.begin()+i, str.begin()+j);
		nums.push_back(sign*stoi(temp));
	}

	int sum = 0;
	for (size_t k = 0; k < nums.size(); k++){
		sum += nums[k];
	}
	cout << sum;
	return 0;
}
