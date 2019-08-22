#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int Di, Pi;
	map<int, int> jobs;
	for (int i = 0; i < N; i++){
		cin >> Di >> Pi;
		jobs[Pi] = Di;
	}

	vector<int> persons(M);
	map<int, int> pays;
	for (int i = 0; i < M; i++){
		cin >> persons[i];
		pays[persons[i]] = 0;
	}

	auto iter2 = jobs.rbegin();
	for (auto iter1 = pays.rbegin(); iter1 != pays.rend(); iter1++){
		for (; iter2 != jobs.rend(); iter2++){
			if (iter2->second <= iter1->first){
				iter1->second  = iter2->first;
				break;
			}
		}
	}

	for (auto p:persons){
		cout << pays[p] << endl;
	}
	return 0;
}
