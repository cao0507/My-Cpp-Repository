#include <iostream>
#include <vector>

using namespace std;


void count_sort(vector<int> &nums, vector<int> &ans, int k){
	vector<int> C(k+1, 0);
	for (size_t i = 0; i < nums.size(); i++)
		C[nums[i]] = C[nums[i]] + 1;

	for (int j = 1; j <= k; j++)
		C[j] += C[j-1];

	for (int i = nums.size()-1; i >= 0; i--){
		ans[C[nums[i]]-1] = nums[i];
		C[nums[i]] -= 1;
	}
}

int max(vector<int> &nums){
	int m = nums[0];
	for (size_t i = 0; i < nums.size(); i++){
		if (m < nums[i])
			m = nums[i];
	}
	return m;
}

void print(vector<int> &vec){
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

int main(){
	int arr[] = {6, 1, 2, 7, 4, 2, 10, 9, 3, 4, 5, 10, 8};
	vector<int> nums(arr, arr+13);
	vector<int> ans(nums.size());
	int k = max(nums);
	count_sort(nums, ans, k);
	print(ans);
	return 0;
}
