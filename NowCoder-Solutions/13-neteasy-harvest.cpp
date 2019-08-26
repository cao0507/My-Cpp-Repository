#include <iostream>
#include <vector>

using namespace std;

int find_heap(vector<int>& apples, int query)
{
	int lo = 0, hi = apples.size()-1;
	int mid;
	while (lo <= hi){
		mid = (lo + hi)/2;
		if (query <= apples[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return hi;
}

int main()
{
	int n, m;
	cin >> n;
	vector<int> apples(n+1, 0);
	int a;
	for (int i = 1; i < n+1; i++){
		cin >> a;
		apples[i] = a + apples[i-1];
	}
	cin >> m;
	int query;
	for (int i = 0; i < m; i++){
		cin >> query;
		cout << find_heap(apples, query) + 1 << endl;
	}
	return 0;
}
