#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int getPathCount(int bridgeNum, vector<vector<int>> bridgeList, string &command){
	int node1 = 0, node2 = 0, node3 = 0;
	if (command[1] != command[0])
		node2++;
}

int main(){
	int bridgeNum;
	cin >> bridgeNum;
	int node1, node2;
	string line;
	vector<vector<int>> bridgeList;
	for (int i = 0; i < bridgeNum; i++){
		cin >> line;
		replace(line.begin(), line.end(), ',', ' ');
		istringstream iss(line);
		string tmp;
		iss >> node1 >> tmp >> node2;
		bridgeList.push_back({node1, node2});
	}
	
	string command;
	cin >> command;
	int res = getPathCount(bridgeNum, bridgeList, command);
	cout << res << endl;
	return 0;
}
