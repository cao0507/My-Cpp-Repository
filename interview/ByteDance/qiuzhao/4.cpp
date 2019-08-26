#include <iostream>
#include <vector>

using namespace std;

int greatCommonDivisor(int a, int b){
	while (1){
		if (a > b)
			a -= b;
		else if (a < b)
			b -= a;
		else
			return a;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> candy(n, 0);
	for (int i = 0; i < n; i++)
		cin >> candy[i];
	int graph[n][n];
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			graph[i][j] = 0;
			if (i != j && greatCommonDivisor(candy[i], candy[j]) > 1){
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
	}
	cout << n-2 << endl;
	return 0;
}
