#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> u(n-1, 0), v(n-1, 0), w(n-1, 0);
	bool flag = false;
	for (int i = 0; i < n-1; i++){
		cin >> u[i] >> v[i] >> w[i];
		if (w[i] == 1)
			flag = true;
	}
	if (flag == false)
		cout << 0 << endl;
	return 0;

}
