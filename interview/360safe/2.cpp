#include <iostream>
#include <map>
using namespace std;

int great_common_divisor(int m, int n)
{
	if (m < n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}
	
	if (n == 0)
		return m;
	else
		return great_common_divisor(n, m % n);
}


int main()
{
	int n;
	cin >> n;
	map<int, int> balls;


	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		balls[tmp]++;
	}

	int divisor = balls.begin()->second;
	for(auto iter = balls.begin(); iter != balls.end(); iter++)
	{
		divisor = great_common_divisor(divisor, iter->second);
	}

	if(divisor < 2)
	{
		cout << 0 << endl;
		return 0;
	}

	int count = 0;
	for(auto iter = balls.begin(); iter != balls.end(); ++iter)
		count += (iter->second)/divisor;

	cout << count << endl;
	return 0;
}
