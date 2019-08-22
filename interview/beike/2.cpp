#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int>& nums){
	int N = nums.size();
	int dp[N];
	for (int i = 0; i < N; i++)
		dp[i] = 1;
	int ans = 1;
	for (int i = 1; i < N; i++){
		for (int j = 0; j < i; j++){
			if (nums[i] > nums[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	return ans;
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
