#include "sort.h"

void Quick_sort::quick_sort(vector<int> &nums){
	_quick_sort(nums, 0, nums.size()-1);
}

void Quick_sort::_quick_sort(vector<int> &nums, int p, int r){
	if (p < r){
		int q = _partition(nums, p, r);
		_quick_sort(nums, p, q-1);
		_quick_sort(nums, q+1, r);
	}
}

int Quick_sort::_partition(vector<int> &nums, int p, int r){
	int x = nums[r];
	int i = p-1;
	for (int j = p; j < r; j++){
		if (nums[j] <= x){
			i = i+1;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i+1], nums[r]);
	return i+1;
}
