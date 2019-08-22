#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> vec(n, 0);
	int c;
	for (int i = 0; i < m; ++i){
		cin >> c;
		vec[c-1]++;
	}
	
	int ans = vec[0];
	for (int i = 1; i < n; ++i)
		if (ans >= vec[i])
			ans = vec[i];

	cout << ans << endl;
	return 0;
}
