#include "sort.h"

void Bubble_sort::bubble_sort(vector<int> &nums){
	vector<int>::size_type i, j;
	for (i = 0; i < nums.size()-1; i++){
		for (j = 0; j+1 < nums.size()-i; j++){
			if (nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
			}
		}
	}
}

