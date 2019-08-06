#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(vector<int>& nums, int first, int last)
{
	int x = nums[first];
	int i = first+1, j = last;
	while (1){
		while (nums[i] <= x)
			i++;
		while (nums[j] > x)
			j--;
		if (i <= j){
			swap(nums[i], nums[j]);
			i++;
			j--;
		}
		else{
			swap(nums[first], nums[j]);
			break;
		}
	}
	return j;
}

void quick_sort(vector<int>& nums, int first, int last)
{
	if (first < last){
		int q = partition(nums, first, last);
		quick_sort(nums, first, q-1);
		quick_sort(nums, q+1, last);
	}
}

int main()
{
	vector<int> nums{2, 7, 10, 1, 4, 6, 3, 13, 9};
	quick_sort(nums, 0, nums.size()-1);
	for(auto n:nums){
		cout << n << " ";
	}
	return 0;
}
