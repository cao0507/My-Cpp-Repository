#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solution(const vector<int>& nums)
{
	int a, b;
	int min_abs = abs(nums[0] - nums[1]);
	for (int i = 0; i < nums.size() - 1; i++){
		int tmp = abs(nums[i] - nums[i+1]);
		if (tmp < min_abs){
			min_abs = tmp;
			a = nums[i];
			b = nums[i+1];
		}
	}
	cout << a << " " << b << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	while (n--){
		int k;
		cin >> k;
		nums.push_back(k);
	}

	solution(nums);
	return 0;
}
