#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> A;
	int cur;
	for (int i = 0; i < N; i++){
		cin >> cur;
		if (A.empty() && cur <= 0)
			continue;
		else if (A.empty())
			A.push_back(cur);
		else if (A.back() >= 0 && cur >= 0){
			A.back() += cur;
		}
		else if (A.back() <= 0 && cur < 0){
			A.back() += cur;
		}
		else
			A.push_back(cur);
	}
	if (A.back() <= 0)
		A.erase(A.end()-1);
	int k = 0;
	int res = 0;
	for (auto a:A){
		cout << a << " ";
		if (a > 0){
			k++;
			res += a;
		}
	}
	cout << endl;
	if (k <= M){
		cout << res << endl;
		return 0;
	}
	else{
		int dp[2][100005] = {0};
		int cur, prev;
		for (int i = 1; i <= M; i++){
			res = 0;
			cur = i & 1;
			prev = (i-1)&1;
			dp[cur][0] = 0;
			for (int j = 1; j <= A.size(); j++){
				res = max(res, dp[prev][j-1]);
				dp[cur][j] = max(res, dp[cur][j-1]) + A[j-1];
			}
		}
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < A.size()+1; j++){
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}
		res = 0;
		for (int i = M; i <= A.size(); i++)
			if (res < dp[cur][i])
				res = dp[cur][i];
	}
	cout << res << endl;
	return 0;
}
