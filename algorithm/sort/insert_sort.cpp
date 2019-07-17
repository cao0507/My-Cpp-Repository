#include "sort.h"

void Insert_sort::insert_sort(vector<int> &nums){
	for (size_t i = 1; i < nums.size(); i++){
		for (size_t j = 0; j < i; j++){
			if (nums[i] < nums[j]){
				swap(nums[i], nums[j]);
			}
		}
	}
}
