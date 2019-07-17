#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getTimes(vector<string>& input){
	int count = 0;

	return count;
}

int main(){
	vector<string> input;
	string line;
	for (int i = 0; i < 3; i++){
		cin >> line;
		input.push_back(line);
	}

	int res = getTimes(input);
	cout << res << endl;
	return 0;
}
