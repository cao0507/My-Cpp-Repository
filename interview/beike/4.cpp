#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++){
		cin >> nums[i];
	}

	int i = 0;
	while (i < N-1 && nums[i] < nums[i+1])
		i++;
	int j = N-1;
	while (j > 0 && nums[j] < nums[j-1])
		j--;

	int ans = 0;
	while (i < j){
		if (nums[i] < nums[j]){
			if (nums[i+1] < nums[i] + 1){
				ans += nums[i] + 1 - nums[i+1];
				nums[i+1] = nums[i] + 1;
			}
			i++;
		}
		else{
			if (nums[j-1] < nums[j] + 1){
				ans += nums[j] + 1 - nums[j-1];
				nums[j-1] = nums[j] + 1;
			}
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}
