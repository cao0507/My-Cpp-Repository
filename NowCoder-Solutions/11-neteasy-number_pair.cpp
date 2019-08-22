#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	long long ans = 0;
	if (k == 0){
		ans = n * n;
		cout << ans << endl;
		return 0;
	}
	for (int y = k+1; y <= n; ++y){
		int t = n / y;
		ans += t*(y-k);
		if (t*y + k <= n)
			ans += n - t*y - k + 1;
	}
	cout << ans << endl;
	return 0;
}
