#include <iostream>
#include <string>

using namespace std;

void eraseBlank(string &str){
	for (auto iter = str.begin(); iter != str.end(); ){
		if (*iter == ' ')
			iter = str.erase(iter);
		else
			iter++;
	}
}
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	eraseBlank(str1);
	eraseBlank(str2);
	int i = 0, j = 0;
	while (i < str1.size() && j < str2.size()){
		for (int k = 0; k < 4 && i+k < str1.size(); k++)
			cout << str1[i+k] << " ";
		i += 4;
		cout << str2[j++] << " ";
	}
	if (i >= str1.size()){
		while (j < str2.size())
			cout << str2[j++] << " ";
	}
	if (j >= str2.size()){
		while (i < str1.size())
			cout << str1[i++] << " ";
	}
	cout << endl;
	return 0;
}
