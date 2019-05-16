/*
 * count stars.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int countStars(vector<vector<int>> &stars, vector<int> &pos){
	int count = 0;

	for (auto iter = stars.begin(); iter != stars.end(); iter++){
		if (pos[0] <= (*iter)[0] && (*iter)[0] <= pos[2] && pos[1] <= (*iter)[1] && (*iter)[1] <= pos[3])
			count++;
	}

	return count;
}

void input(vector<vector<int>> &stars, vector<vector<int>> &rects){
	int n, m;
	cin >> n;
	while (n--){
		int x, y;
		cin >> x >> y;
		vector<int> tmp = {x, y};
		stars.push_back(tmp);
	}

	cin >> m;
	while (m--){
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		vector<int> tmp = {a1, b1, a2, b2};
		rects.push_back(tmp);
	}

}

int main() {
	vector<vector<int>> stars, rects;
	input(stars, rects);

	int count;
	for (auto iter = rects.begin(); iter != rects.end(); iter++){
		count = countStars(stars, *iter);
		cout << count << endl;
	}
}
