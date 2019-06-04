#include "sort.h"

/*
 * 快速排序：不是稳定的，不稳定发生在主元与nums[j]交换的时刻。
 */


//void Quick_sort::quick_sort(vector<int> &nums){
//	_quick_sort(nums, 0, nums.size()-1);
//}
//
//void Quick_sort::_quick_sort(vector<int> &nums, int p, int r){
//	if (p < r){
//		int q = _partition(nums, p, r);
//		_quick_sort(nums, p, q-1);
//		_quick_sort(nums, q+1, r);
//	}
//}
//
//int Quick_sort::_partition(vector<int> &nums, int p, int r){
//	int x = nums[r];
//	int i = p-1;
//	for (int j = p; j < r; j++){
//		if (nums[j] <= x){
//			i = i+1;
//			swap(nums[i], nums[j]);
//		}
//	}
//	swap(nums[i+1], nums[r]);
//	return i+1;
//}

void Quick_sort::quick_sort( vector<int> &nums ){
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
	int x = nums[p];
	int i = p+1, j = r;
	while (1){
		while (x >= nums[i])
			i++;
		while (x < nums[j])
			j--;
		if (i <= j){
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
		else{
			swap(nums[p], nums[j]);
			break;
		}
	}
	return j;
}
