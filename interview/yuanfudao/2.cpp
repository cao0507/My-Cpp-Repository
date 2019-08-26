#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; i++){
		int T;
		cin >> T;
		vector<int> P(T, 0);
		for (int j = 0; j < T; j++){
			cin >> P[j];
		}
		int res = 0;
		while (P[T-3] > 0){
			sort(P.begin(), P.end());
			res += P[T-3];
			P[T-2] -= P[T-3];
			P[T-1] -= P[T-3];
			P[T-3] = 0;
		}
		
		cout << res << endl;
	}
	return 0;
}
