#include "sort.h"

void Select_sort::select_sort(vector<int> &nums){
	for (size_t i = 0; i < nums.size()-1; i++){
		size_t min_index = i;
		for (size_t j = i+1; j < nums.size(); j++){
			if (nums[j] < nums[min_index]){
				min_index = j;
			}
		}
		swap(nums[i], nums[min_index]);
	}
}
