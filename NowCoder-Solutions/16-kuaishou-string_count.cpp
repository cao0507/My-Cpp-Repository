#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int dict[26] = {0};
	for (int i = 0; i < str.size(); i++)
		dict[str[i] - 'a']++;

	string res;
	for (int i = 0; i < 26; i++){
		if (dict[i] == 0)
			continue;
		else if (dict[i] == 1){
			res += 'a' + i;
		}
		else{
			res += 'a' + i;
			res += to_string(dict[i]);
		}
	}
	cout << res << endl;
	return 0;
}
