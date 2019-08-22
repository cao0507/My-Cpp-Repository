#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, X, A, B, Hi, Mi;
	cin >> N;
	vector<int> clocks(N);
	for (int i = 0; i < N; ++i){
		cin >> Hi >> Mi;
		clocks[i] = Hi*60 + Mi;
	}
	cin >> X;
	cin >> A >> B;
	int goclass = A*60 + B - X;

	sort(clocks.begin(), clocks.end());

	int lo = 0, hi = N - 1;
	int mid;
	while (lo <= hi){
		mid = (lo + hi)/2;
		if (clocks[mid] > goclass)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << clocks[hi]/60 <<" " << clocks[hi]%60 << endl;
	return 0;
}
