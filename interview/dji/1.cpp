#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(const vector<int>& value, const vector<int>& weight, vector<int>& res, int N, int X){
	int dp[X + 1];
	for (int i = 0; i <= X; i++)
		dp[i] = 0;

	for (int i = 0; i < N; i++){
		for (int v = X; v >= weight[i]; v--){
			dp[v] = max(dp[v], dp[v - weight[i]] + value[i]);
		}
	}
	res.push_back(dp[X]);
}

int main(){
	int T;
	cin >> T;
	vector<int> res;
	while (T--){
		int N, X;
		cin >> N >> X;
		vector<int> value;
		vector<int> weight;
		int v, w;
		for (int i = 0; i < N; i++){
			cin >> v >> w;
			value.push_back(v);
			weight.push_back(w);
		}

		solution(value, weight, res, N, X);
	}

	for (auto n:res){
		cout << n << endl;
	}
	return 0;
}
