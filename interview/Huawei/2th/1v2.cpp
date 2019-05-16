#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

void rotate_Matrix(vector<vector<int>>& nums){
	int n = nums.size();
	for (auto iter = nums.begin(); iter != nums.end(); iter++){
		reverse(iter->begin(), iter->end());
	}
	for (int i = 0; i < n - 1; i++){
		for (int j = 0; j < n - i - 1; j++){
			swap(nums[i][j], nums[n - 1- j][n - 1 - i]);
		}
	}
}

int main() {
	int N, M;
	cin >> N;
	vector<vector<int>> nums;
	for(int i = 0; i < N; i++){
		vector<int> tmp;
		for (int j = 0; j < N; j++){
			int t;
			cin >> t;
			tmp.push_back(t);
		}
		nums.push_back(tmp);
	}

	cin >> M;
	M = M%4;

	for (int k = 0; k < M; k++)
		rotate_Matrix(nums);

	for(auto iter = nums.begin(); iter != nums.end(); iter++){
		for (auto iter2 = iter->begin(); iter2 != iter->end(); iter2++){
			cout << *iter2 << " ";
		}
		cout << endl;
	}
	return 0;
}
