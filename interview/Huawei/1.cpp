#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int>::size_type MAX_SIZE = 0;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> input;
	string line;
	while(getline(cin, line)){
		replace(line.begin(), line.end(), ',', ' ');
		istringstream numbers(line);
		int num;
		vector<int> vec;
		while (numbers >> num){
			vec.push_back(num);	
		}
		if (vec.size() > MAX_SIZE)
			MAX_SIZE = vec.size();
		input.push_back(vec);
	}

	//for (vector<int>::size_type i = 0; i < input.size(); i++){
		//for (vector<int>::size_type j = 0; j < input[i].size(); j++){
			//cout << input[i][j] << " ";
		//}
	//}
	//cout << endl;
	vector<int>::size_type count = 0;
	vector<int> res;
	while (count*n <= MAX_SIZE){
		for (vector<int>::size_type i = 0; i < input.size(); i++ ){
			for (vector<int>::size_type j = count*n; j < (count+1)*n && j < input[i].size(); j++)
				res.push_back(input[i][j]);
		}
		count++;
	}
	vector<int>::size_type i;
	for (i = 0; i < res.size()-1; i++){
		cout << res[i] << ',';
	}
	cout << res[i] << endl;
	return 0;
}
