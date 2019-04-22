#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> coins;
	int c;
	for (int i = 0; i < n; i++){
		cin >> c;
		coins.push_back(c);
	}

	sort(coins.begin(), coins.end());
	if (coins[0] != 1){
		cout << "-1" << endl;
		return 0;
	}

	int count = 1;
	int s = 1;
	vector<int> res;
	res.push_back(1);
	while (s < m){
		int i;
		for (i = 0; i < n; i++){
			if (coins[i] > s+1)
				break;
		}
		s += coins[i-1];
		res.push_back(coins[i-1]);
		count++;
	}

	cout << count << endl;
	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	return 0;
}
