#include <iostream>
#include <vector>

using namespace std;

int basic_binary_search(const vector<int>& nums, int target);
int find_first_greater(const vector<int>& nums, int target);
int find_last_less(const vector<int>& nums, int target);
int find_first_greater_equal(const vector<int>& nums, int target);
int find_last_less_equal(const vector<int>& nums, int target);
int find_the_first(const vector<int>& nums, int target);
int find_the_last(const vector<int>& nums, int target);

int basic_binary_search(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		//target在左边，改右边界
		if (target < nums[mid])
			right = mid - 1;
		//target在右边，改左边界
		else if (target > nums[mid])
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

//查找第一个大于target的元素位置
int find_first_greater(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (left < (int)nums.size())
		return left;
	return -1;
}

//查找最后一个小于target的元素位置
int find_last_less(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target <= nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (right >= 0)
		return right;
	return -1;
}

//查找第一个大于等于target的元素位置
int find_first_greater_equal(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target <= nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (left < (int)nums.size())
		return left;
	return -1;
}

//查找最后一个小于等于target的元素位置
int find_last_less_equal(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (right >= 0)
		return right;
	return -1;
}

//查找第一个等于target的元素位置
int find_the_first(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target <= nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (left < (int)nums.size() && nums[left] == target)
		return left;
	return -1;
}

//查找最后一个等于target的元素位置
int find_the_last(const vector<int>& nums, int target)
{
	int left = 0, right = nums.size()-1;
	int mid;
	while (left <= right){
		mid = left + (right - left)/2;
		if (target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	if (right >= 0 && nums[right] == target)
		return right;
	return -1;
}

int main()
{
	int arr[] = {-1, 1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8};
	vector<int> nums(arr, arr + sizeof(arr)/4);

	//cout << "find 2 at: " << basic_binary_search(nums, 2) << endl;
	//cout << "find 3 at: " << basic_binary_search(nums, 3) << endl;

	cout << "find_first_greater 9 at: " << find_first_greater(nums, 9) << endl;
	//cout << "find_last_less 3 at: " << find_last_less(nums, 3) << endl;

	//cout << "find_first_greater_equal 3 at: " << find_first_greater_equal(nums, 3) << endl;
	//cout << "find_last_less_equal 3 at: "  << find_last_less_equal(nums, 3) << endl;

	//cout << "find_the_first 3 at: " << find_the_first(nums, 3) << endl;
	//cout << "find_the_last 3 at: " << find_the_last(nums, 3) << endl;
	return 0;
}
