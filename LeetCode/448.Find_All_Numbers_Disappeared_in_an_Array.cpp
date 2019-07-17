#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums){
	vector<int> res;

	for (size_t i = 0; i < nums.size(); i++){
		int tmp = abs(nums[i]) - 1;
		if (nums[tmp] > 0)
			nums[tmp] = -nums[tmp];
	}

	for (size_t i = 0; i < nums.size(); i++){
		if (nums[i] > 0)
			res.push_back(i + 1);
	}

	return res;
}

void print(vector<int> &nums){
	for (auto iter = nums.begin(); iter != nums.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

int main(){
	int arr[] = {1, 2, 2, 3, 3, 4, 7, 8};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));

	vector<int> res = findDisappearedNumbers(nums);

	print(nums);
	print(res);

	return 0;
}
