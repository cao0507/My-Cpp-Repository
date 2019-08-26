#include <iostream>
#include <vector>

using namespace std;

//逆时针旋转90度
void rotate(int matrix[4][4]){
	int tmp[4][4] = {0};
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			tmp[i][j] = matrix[j][4-1-i];
		}
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			matrix[i][j] = tmp[i][j];
	}
}

void moveLeft(int matrix[4][4]){
	for (int i = 0; i < 4; i++){
		int cur = 0;
		int lastValue = 0;
		for (int j = 0; j < 4; j++){
			if (matrix[i][j] == 0)
				continue;
			if (lastValue == 0){
				lastValue = matrix[i][j];
			}
			else{
				if (lastValue == matrix[i][j]){
					matrix[i][cur] = lastValue*2;
					lastValue = 0;
				}
				else{
					matrix[i][cur] = lastValue;
					lastValue = matrix[i][j];
				}
				++cur;
			}
			matrix[i][j] = 0;
		}
		if (lastValue != 0)
			matrix[i][cur] = lastValue;
	}
}

void moveUp(int matrix[4][4]){
	rotate(matrix);
	moveLeft(matrix);
	rotate(matrix);
	rotate(matrix);
	rotate(matrix);
}

void moveDown(int matrix[4][4]){
	rotate(matrix);
	rotate(matrix);
	rotate(matrix);
	moveLeft(matrix);
	rotate(matrix);
}

void moveRight(int matrix[4][4]){
	rotate(matrix);
	rotate(matrix);
	moveLeft(matrix);
	rotate(matrix);
	rotate(matrix);
}


int main()
{
	int op;
	cin >> op;
	int matrix[4][4];
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			cin >> matrix[i][j];
	}

	if (op == 1)
		moveUp(matrix);
	else if (op == 2)
		moveDown(matrix);
	else if (op == 3)
		moveLeft(matrix);
	else if (op == 4)
		moveRight(matrix);

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
