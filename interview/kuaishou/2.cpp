#include <iostream>
#include <set>

using namespace std;

int func(int num){
	int res = 0;
	int remain = 0;
	while (num){
		remain = num%10;
		res += remain*remain;
		num /= 10;
	}
	return res;
}

int main()
{
	int m;
	cin >> m;
	while (m--){
		int num;
		cin >> num;
		set<int> my_set;
		while (num != 1){
			if (my_set.find(num) != my_set.end()){
				cout << "false" << endl;
				break;
			}
			else
				my_set.insert(num);
			num = func(num);
		}
		if (num == 1)
			cout << "true" << endl;
	}
	return 0;
}
