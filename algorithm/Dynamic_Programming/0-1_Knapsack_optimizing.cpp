#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(const vector<int>& weight, const vector<int>& value, int W)
{
	int n = weight.size();
	int dp[W + 1];

    for (int i = 0; i <= W; ++i)
        dp[i] = 0;

    for (int i = 0; i < n; i++){
        for (int w = W; w >= weight[i]; w--){
			dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }
    return dp[W];
}

int main()
{
	vector<int> weight, value;
	int w, v;
	int W;
	cin >> W;
	while (cin >> w >> v){
		weight.push_back(w);
		value.push_back(v);
	}
	int max_value = solution(weight, value, W);
	cout << max_value << endl;
    return 0;
}
