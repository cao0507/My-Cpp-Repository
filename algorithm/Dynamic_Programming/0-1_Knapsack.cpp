#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(const vector<int>& weight, const vector<int>& value, int V)
{
	int N = weight.size();
	int dp[N+1][V+1];

	for (int i = 0; i < N+1; i++)
		dp[i][0] = 0;
	for (int j = 1; j < V+1; j++)
		dp[0][j] = 0;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= V; j++){
			if (j > weight[i-1])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + value[i-1]);
			else
				dp[i][j] = dp[i-1][j-1];
		}
	}

	return dp[N][V];
}

int main()
{
	int V;
	cin >> V;
	vector<int> weight, value;
	int w, v;
	while (cin >> w >> v){
		weight.push_back(w);
		value.push_back(v);
	}

	int max_value = knapsack(weight, value, V);
	cout << max_value << endl;
	return 0;
}
