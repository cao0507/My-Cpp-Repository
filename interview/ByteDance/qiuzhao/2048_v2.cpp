#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int direction;
	cin >> direction;
	int m[4][4] = {0};
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cin >> m[i][j];
		}
	}

	if (direction == 1){
		for (int j = 0; j < 4; j++){
			for (int i = 0; i < 4; i++){//下落
				if (m[i][j] == 0){
					for (int k = i+1; k < 4; k++){
						if (m[k][j] != 0){
							swap(m[i][j], m[k][j]);
							break;
						}
					}
				}
			}
			for (int i = 0; i < 3; i++){//合并
				if (m[i][j] == m[i+1][j]){
					m[i][j] = 2*m[i][j];
					m[i+1][j] = 0; 
				}
			}
			for (int i = 0; i < 4; i++){//下落
				if (m[i][j] == 0){
					for (int k = i+1; k < 4; k++){
						if (m[k][j] != 0){
							swap(m[i][j], m[k][j]);
							break;
						}
					}
				}
			}
		}
	}

	if (direction == 2){
		for (int j = 0; j < 4; j++){
			for (int i = 3; i >= 0; i--){//下落
				if (m[i][j] == 0){
					for (int k = i-1; k >= 0; k--){
						if (m[k][j] != 0){
							swap(m[i][j], m[k][j]);
							break;
						}
					}
				}
			}
			for (int i = 3; i > 0; i--){//合并
				if (m[i][j] == m[i-1][j]){
					m[i][j] = 2*m[i][j];
					m[i-1][j] = 0; 
				}
			}
			for (int i = 3; i >= 0; i--){//下落
				if (m[i][j] == 0){
					for (int k = i-1; k >= 0; k--){
						if (m[k][j] != 0){
							swap(m[i][j], m[k][j]);
							break;
						}
					}
				}
			}
		}
	}

	if (direction == 3){
		for (int i = 0; i < 4; i++){//下落
			for (int j = 0; j < 4; j++){
				if (m[i][j] == 0){
					for (int k = j+1; k < 4; k++){
						if (m[i][k] != 0){
							swap(m[i][j], m[i][k]);
							break;
						}
					}
				}
			}
			for (int j = 0; j < 3; j++){//合并
				if (m[i][j] == m[i][j+1]){
					m[i][j] = 2*m[i][j];
					m[i][j+1] = 0; 
				}
			}
			for (int j = 0; j < 4; j++){//下落
				if (m[i][j] == 0){
					for (int k = j+1; k < 4; k++){
						if (m[i][k] != 0){
							swap(m[i][j], m[i][k]);
							break;
						}
					}
				}
			}
		}
	}

	if (direction == 4){
		for (int i = 0; i < 4; i++){//下落
			for (int j = 3; j >= 0; j--){
				if (m[i][j] == 0){
					for (int k = j-1; k > 0; k--){
						if (m[i][k] != 0){
							swap(m[i][j], m[i][k]);
							break;
						}
					}
				}
			}
			for (int j = 3; j > 0; j--){//合并
				if (m[i][j] == m[i][j-1]){
					m[i][j] = 2*m[i][j];
					m[i][j-1] = 0; 
				}
			}
			for (int j = 3; j >= 0; j--){//下落
				if (m[i][j] == 0){
					for (int k = j-1; k > 0; k--){
						if (m[i][k] != 0){
							swap(m[i][j], m[i][k]);
							break;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

}
