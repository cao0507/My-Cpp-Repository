#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int>> solution(int start, int end, int m)
{
	vector<stack<int>> res;
	if(m <= 0){
		stack<int> ss;
		res.push_back(ss);
		return res;
	}else if(start > end){
		stack<int> ss;
		for(int i = 0; i < m; i++)
		{
			ss.push(end);
		}
		res.push_back(ss);
		return res;
	}

	for(int i = start; i <= end; i++){
		vector<stack<int>> temp = solution(i, end, m-1);
		for(size_t j = 0; j < temp.size(); j++){
			temp[j].push(i);
			res.push_back(temp[j]);
		}
	}
	return res;
}

int main(){
	int n, k;
	cin >> n;
	cin >> k;
	
	vector<stack<int>> res = solution(0, n, k-1);

	cout << res.size() << endl;

	for(auto iter = res.rbegin(); iter != res.rend(); iter++){
		int i = 1;
		while(iter->size() > 0){
			int ii = iter->top();
			iter->pop();
			for(; i <= ii; i++)
				cout << '*';
			cout << '|';

		}
		for(; i <= n; i++)
			cout << '*';
		cout << endl;
	}

	return 0;
}
