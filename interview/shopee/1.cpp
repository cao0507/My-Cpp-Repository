#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	while (!isalnum(str[0])){
		str.erase(str.begin());
	}
	int flag = 0;
	for (auto iter = str.begin(); iter != str.end(); ){
		if (!isalnum(*iter)){
			iter = str.erase(iter);
			flag = 1;
			continue;
		}
		else if (flag == 0)
			*iter = tolower(*iter);
		else if (flag == 1){
			*iter = toupper(*iter);
			flag = 0;
		}
		iter++;
	}
	cout << str << endl;
	return 0;
}
