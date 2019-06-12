#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//int arr[] = { 4, 2, 9, 7, 1, 19 };
	//vector<int> nums(arr, arr+(sizeof(arr)/sizeof(int)));
	//vector<int> nums{4, 2, 9, 7, 1, 19};
	vector<int> nums = {4, 2, 9, 7, 1, 19};

	sort(nums.begin(), nums.end());
	for (auto iter = nums.begin(); iter != nums.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	return 0;
}
