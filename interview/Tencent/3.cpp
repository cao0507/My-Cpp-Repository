#include <iostream>
#include <vector>

using namespace std;

vector<int> d;
vector<int> p;

int dfs(int id, int sum, int len){
	int res = 0;
	if (id == len-1){
		if (sum < d[id])
			return p[id];
		else
			return 0;
	}

	if (sum >= d[id])
		res += min(p[id] + dfs(id+1, sum+d[id], len), dfs(id+1, sum, len));
	else
		res += p[id] + dfs(id+1, sum+d[id], len);
	return res;
}

int main(){
	int N;
	cin >> N;
	int k;
	for (int i = 0; i < N; i++){
		cin >> k;
		d.push_back(k);
	}
	for (int i = 0; i < N; i++){
		cin >> k;
		p.push_back(k);
	}

	cout << dfs(0, 0, N) << endl;
	return 0;
}
