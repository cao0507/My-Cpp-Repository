#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
	return a[2] > b[2];
}

int find_max(vector<vector<int>>& mm){
	int ans = mm[0][2];
	int i = mm[0][0];
	int j = mm[0][1];

	for(auto iter = mm.begin(); iter != mm.end();){
		if ((*iter)[0] == i || (*iter)[1] == j)
			iter = mm.erase(iter);
		else
			++iter;
	}
	return ans;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	vector<vector<int>> mm;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cin >> b[i];
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			vector<int> tmp;
			tmp.push_back(i);
			tmp.push_back(j);
			tmp.push_back((a[i] + b[j]) % m);
			mm.push_back(tmp);
		}
	}

	sort(mm.begin(), mm.end(), cmp);

	for (int i = 0; i < n; ++i){
		cout << find_max(mm) << endl;
	}

	return 0;
}
