#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	string num;
	cin >> num;
	string tmp = num;
	sort(tmp.begin(), tmp.end());
	if (tmp == num){
		cout << 0 << endl;
		return 0;
	}
	char min_index = num.size()-1;
	int i;
	for (i = num.size()-2; i >= 0; i--){
		if (num[min_index] >= num[i])
			min_index = i;
		else
			break;
	}
	cout << i << endl;
	int j;
	for (j = min_index; j < num.size(); j++){
		if (num[min_index] > num[i])
			break;
	}
	j = j-1;
	cout << j << endl;
	if (num[min_index] == '0' && i == 0){
		cout << 0 << endl;
		return 0;
	}
	swap(num[i], num[j]);
	sort(num.begin()+i+1, num.end(), greater<char>());
	cout << num << endl;
	return 0;
}
