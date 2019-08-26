#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> W(N+1, 0);
	int sum = 0;
	for (int i = 1; i <= N; i++){
		cin >> W[i];
		sum += W[i];
	}
	int max_w = sum/2;
	int dp[max_w+1] = {};
	for (int i = 1; i <= N; i++){
		for (int j = max_w; j > 0; j--){
			if (j >= W[i])
				dp[j] = max(dp[j], dp[j-W[i]] - 1);
		}
	}
	/*int dp[N+1][max_w+1] = {};
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= max_w; j++){
			if (j >= W[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + 1);
			else
				dp[i][j] = dp[i-1][j];
		}
	}*/
	cout << max_w - min(s1, s2) << " ";
	cout <<  2*dp[max_w] + N << endl;
	return 0;
}
