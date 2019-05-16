#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& nums){
	vector<vector<int>> res;
	for (size_t j = 0; j < nums.size(); j++){
		vector<int> temp;
		for (int i = nums.size() - 1; i >= 0; i--){
			temp.push_back(nums[i][j]);
		}
		res.push_back(temp);
	}
	return res;
}

int main() {
	int N, M;
	cin >> N;
	vector<vector<int>> nums;
	for (int i = 0; i < N; i++){
		vector<int> temp;
		for (int j = 0; j < N; j++){
			int k;
			cin >> k;
			temp.push_back(k);
		}
		nums.push_back(temp);
	}

	cin >> M;
	M = M%4;

	for (int k = 0; k < M; k++)
		nums = rotate(nums);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
