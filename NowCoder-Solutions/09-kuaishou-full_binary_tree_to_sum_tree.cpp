#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void sum_tree(vector<int>& inorder, int left, int right){
	int mid = (left + right)/2;
	if (mid == left){
		inorder[mid] = 0;
		return ;
	}
	inorder[mid] = accumulate(inorder.begin()+left, inorder.begin()+right, -inorder[mid]);
	sum_tree(inorder, left, mid);
	sum_tree(inorder, mid+1, right);
}

int main()
{
	string line;
	int k;
	vector<int> preorder, inorder;
	getline(cin, line);
	istringstream is(line);
	while (is >> k)
		preorder.push_back(k);

	getline(cin, line);
	is = istringstream (line);
	while (is >> k)
		inorder.push_back(k);

	sum_tree(inorder, 0, inorder.size());
	for (auto n:inorder)
		cout << n << " ";
	cout << endl;
	return 0;
}
