#include <iostream>
#include <vector>

using namespace std;

int prize(vector<int> &nums){
	int count = 0, n = nums.size();
	vector<int> gifts(n, 1);
	int i, j;
	for (i = 0; i < n-1; i++){
		if (nums[i+1] > nums[i])
			gifts[i+1] = gifts[i]+1;	
	}
	i = 0, j = n-1;
	while (nums[i] > nums[j]){
		gifts[i] = gifts[j]+1;
		i = (i+1)%n;
		j = (j+1)%n;
	}
	for (i = n-1, j = n-2; i >= 1; i--, j--){
		if (nums[j] > nums[i] && gifts[j] <= gifts[i])
			gifts[j] = gifts[i]+1;
	}
	i = 0, j = n-1;
	while (nums[j] > nums[i]){
		if (nums[j] > nums[i] && gifts[j] <= gifts[i])
			gifts[j] = gifts[i]+1;
		if (i == 0)
			i = n-1;
		else
			i--;
		
		if (j == 0)
			j = n-1;
		else 
			j--;
	}

	for (i = 0; i < n; i++)
		count += gifts[i];

	return count;
}

int main(){
	int N, n, m;
	vector<int> res;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> n;
		vector<int> nums;
		for (int j = 0; j < n; j++){
			cin >> m;
			nums.push_back(m);
		}
		res.push_back(prize(nums));
	}

	for (int i = 0; i < N; i++){
		cout << res[i] << endl;
	}
	return 0;
}
