#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int Aij;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			cin >> Aij;
			A[i][j] = Aij;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			ans += 2;
			//left
			if (j == 0)
				ans += A[i][j];
			else{
				if (A[i][j] > A[i][j-1])
					ans += A[i][j] - A[i][j-1];
			}

			//right
			if (j == M-1)
				ans += A[i][j];
			else{
				if (A[i][j] > A[i][j+1])
					ans += A[i][j] - A[i][j+1];
			}

			//front
			if (i == 0)
				ans += A[i][j];
			else{
				if (A[i][j] > A[i-1][j])
					ans += A[i][j] - A[i-1][j];
			}

			//back
			if (i == N-1)
				ans += A[i][j];
			else{
				if (A[i][j] > A[i+1][j])
					ans += A[i][j] - A[i+1][j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
