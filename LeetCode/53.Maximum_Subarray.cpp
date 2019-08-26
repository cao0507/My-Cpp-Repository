#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
/*
int main()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	const int n = sizeof(arr)/4;
	int dp[n+1] = {0};
	dp[0] = -1;
	for (int i = 1; i <= n; i++){
		dp[i] = max(dp[i-1] + arr[i-1], arr[i-1]);
	}
	int res = dp[1];
	for (int i = 1; i <= n; i++){
		res = max(res, dp[i]);
		cout << dp[i] << endl;
	}
	cout << res << endl;
	return 0;
}
*/

int main()
{
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	int res = arr[0], temp_sum = arr[0];
	for (int i = 1; i < sizeof(arr)/4; i++){
		if (temp_sum < 0)
			temp_sum = arr[i];
		else
			temp_sum += arr[i];
		if (res < temp_sum)
			res = temp_sum;
	}
	cout << res << endl;
	return 0;
}
