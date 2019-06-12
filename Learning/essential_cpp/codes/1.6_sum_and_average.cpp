#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> nums;
	int val;
	while (cin >> val){
		nums.push_back(val);
	}
	int Sum = 0;
	for (auto &n:nums){
		Sum += n;
	}
	float average = (float)Sum/nums.size();
	cout << "sum= " << Sum << endl;
	cout << "average= " << average << endl;
	return 0;
}
