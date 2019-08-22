#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_greater(const vector<int>& dp, int target){
	int lo = 0, hi = dp.size();
	while (lo < hi){
		int mid = lo + (hi - lo)/2;
		if (dp[mid] < target)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

int solution(const vector<int>& nums){
	int N = nums.size();
	vector<int> dp;
	dp.push_back(nums[0]);
	for (int i = 1; i < N; i++){
		if (nums[i] > dp.back())
			dp.push_back(nums[i]);
		else{
			int k = find_greater(dp, nums[i]);
			dp[k] = nums[i];
		}
	}
	return dp.size();
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums;
	while (N--){
		int a;
		cin >> a;
		nums.push_back(a);
	}
	
	int ans = solution(nums);
	cout << ans;
	return 0;
}
