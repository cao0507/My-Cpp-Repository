#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int dp[1001] = {1};
	int t;
	for (int i = 1; i < 1001; i++){
		t = 1;
		while (t <= i){
			dp[i] = (dp[i] + dp[i-t])%1000000003;
			t *= 2;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}
