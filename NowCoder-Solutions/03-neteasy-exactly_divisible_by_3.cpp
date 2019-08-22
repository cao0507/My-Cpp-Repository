#include <iostream>

using namespace std;

/*
int main()
{
	int l, r;
	if (cin >> l >> r){
	
		int k = r - l + 1;
		int n = 2 * (k / 3);
		if (k % 3 == 0){
			cout << n << endl;
		}
		else if (k % 3 == 1){
			if (l % 3 == 1)
				cout << n << endl;
			else
				cout << n + 1 << endl;
		}
		else{
			if (l % 3 == 1)
				cout << n + 1 << endl;
			else if (l % 3 == 2)
				cout << n + 2 << endl;
			else
				cout << n + 1 << endl;
		}
	}
	return 0;
}
*/

int main()
{
	int l, r;
	if (cin >> l >> r){
		int m = 2 * ((l - 1) / 3) + (l - 1 + 2)%3;
		int n = 2 * (r / 3) + (r + 2)%3;
		cout << n - m << endl;
	}
	return 0;
}
