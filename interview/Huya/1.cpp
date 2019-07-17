#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	string ab = to_string(a)+to_string(b);
	string ba = to_string(b)+to_string(a);
	if (ab > ba)
		return false;
	else
		return true;
}

int main(){
	vector<int> nums;
	int num;
	while (cin >> num){
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end(), cmp);
	for (size_t i = 0; i < nums.size(); i++)
		cout << nums[i];
	cout << endl;
	return 0;
}
