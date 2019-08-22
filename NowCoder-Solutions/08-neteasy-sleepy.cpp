#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<vector<int>> sleep(n, vector<int> (2, 0));
	for (int i = 0; i < n; ++i){
		cin >> sleep[i][0];
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		cin >> sleep[i][1];
		if (sleep[i][1] == 1)
			ans += sleep[i][0];
	}

	int max = 0;
	int tmp = 0;
	for (int i = 0; i < k; ++i){
		if (sleep[i][1] == 0){
			tmp += sleep[i][0];
		}
	}
	max = tmp;
	for (int i = k; i < n; ++i){
		if (sleep[i][1] == 0)
			tmp += sleep[i][0];
		if (sleep[i-k][1] == 0)
			tmp -= sleep[i-k][0];
		if (tmp > max)
			max = tmp;
	}

	ans += max;
	cout << ans << endl;
	return 0;
}
