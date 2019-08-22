#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> d(n, 0);
	for (int i = 0; i < n; i++){
		cin >> d[i];
	}

	long long bonus = 0;
	int i = 0, j = n - 1;
	long long b1 = d[i], b2 = d[j];
	while (i < j){
		if (b1 == b2){
			bonus = b1;
			b1 += d[++i];
			b2 += d[--j];
		}
		else if (b1 < b2){
			b1 += d[++i];
		}
		else{
			b2 += d[--j];
		}
	}
	cout << bonus << endl;
	return 0;
}
