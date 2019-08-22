#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int knapsack(int n, int w, vector<int>& v)
{
	if (w <= 0)
		return 0;
	if (n == 1){
		if (v[n] <= w)
			return 2;
		else
			return 1;
	}
	return knapsack(n-1, w, v) + knapsack(n-1, w - v[n], v);
}

int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> v(n+1, 0);
	long long sum = 0;
	for (int i = 1; i <= n; ++i){
		cin >> v[i];
		sum += v[i];
	}
	int ans = 0;
	if (sum <= w)
		ans = pow(2, n);
	else
		ans = knapsack(n, w, v);
	cout << ans << endl;
	return 0;
}
