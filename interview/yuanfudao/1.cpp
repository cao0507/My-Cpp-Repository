#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> nums(n, 0);
	map<int, int> my_map;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
		my_map[nums[i]]++;
	}

	for (int i = 0; i < n; i++){
		if (my_map[nums[i]] > m)
			continue;
		cout << nums[i] << " ";
	}
	return 0;
}
