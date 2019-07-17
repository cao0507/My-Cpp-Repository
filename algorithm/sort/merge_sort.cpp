#include "sort.h"

void Merge_sort::merge_sort(vector<int> &nums){
	_merge_sort(nums, 0, nums.size()-1);
}

void Merge_sort::_merge_sort(vector<int> &nums, int begin, int end){
	if (begin < end){
		int mid = (begin + end)/2;
		_merge_sort(nums, begin, mid);
		_merge_sort(nums, mid+1, end);
		_merge(nums, begin, mid, end);
	}
}

void Merge_sort::_merge(vector<int> &nums, int begin, int mid, int end){
	vector<int> tmp; /* 非空间原址排序 */
	int i = begin, j = mid+1;
	while ( (i != mid+1) && (j != end+1) ){
		if (nums[i] <= nums[j])
			tmp.push_back(nums[i++]);
		else
			tmp.push_back(nums[j++]);
	}

	while ( i != mid+1 )
		tmp.push_back(nums[i++]);

	while ( j != end+1 )
		tmp.push_back(nums[j++]);

	for (size_t i = 0; i < tmp.size(); i++)
		nums[begin+i] = tmp[i];
}
