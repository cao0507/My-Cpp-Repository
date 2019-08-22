#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> input(3, 0);
	cin >> input[0] >> input[1] >> input[2];
	sort(input.begin(), input.end());
	
	int ans = max(input[0]+input[1], input[0]*input[1]);
	if (input[2] == 1)
		ans += 1;
	else
		ans *= input[2];

	cout << ans << endl;
	return 0;
}
