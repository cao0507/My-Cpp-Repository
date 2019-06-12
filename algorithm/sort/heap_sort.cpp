#include "sort.h" 

void Heap_sort::heap_sort(vector<int> &nums){
	build_heap(nums);
	int heap_size = nums.size();
	for (int i = nums.size()-1; i > 0; i--){
		swap(nums[0], nums[i]);
		heap_size--;
		heapify(nums, 0, heap_size);
	}	
}

void Heap_sort::build_heap(vector<int> &nums){
	for (int i = nums.size()/2 - 1; i >= 0; i--)
		heapify(nums, i, nums.size()-1);
}

void Heap_sort::heapify(vector<int> &nums, int root, int heap_size){
	int left = 2*root, right = 2*root+1;
	int max_index = root;
	if ( left < heap_size && nums[left] > nums[root] )
		max_index = left;
	if ( right < heap_size && nums[right] > nums[max_index] )
		max_index = right;
	if ( max_index != root ){
		swap(nums[max_index], nums[root]);
		heapify(nums, max_index, heap_size);
	}
}
