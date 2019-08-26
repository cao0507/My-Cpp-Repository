#include <iostream>

using namespace std;

int main(){
    int n;
	cin >> n;	
	int dp[2][n] = {0};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cout << dp[i][j] << " ";
    return 0;
}
