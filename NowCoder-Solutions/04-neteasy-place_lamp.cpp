#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int k = 0;
		for (int j = 0; j < n; ){
			if (s[j] == '.'){
				k++;
				j += 3;
			}
			else
				j += 1;
		}
		cout << k << endl;
	}
	return 0;
}
