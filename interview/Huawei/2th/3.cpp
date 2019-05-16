#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(string &str1, string &str2, int &count){
	int len1 = str1.size();
	int len2 = str2.size();
	int dp[len1+1][len2+1];
	for (int i = 0; i <= len1; i++)
		dp[i][0] = i;
	for (int j = 0; j <= len2; j++)
		dp[0][j] = j;

	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			int tmp;
			if (str1[i-1] == str2[j-1])
				tmp = 0;
			else
				tmp = 1;
			dp[i][j] = min(dp[i-1][j-1] + tmp, min(dp[i][j-1], dp[i-1][j]) + 1);
		}
	}
	count += dp[len1][len2];
}

int main() {
	int N;
	cin >> N;
	vector<string> text1;
	vector<string> text2;
	string str;
	for (int i = 0; i < N; i++){
		cin >> str;
		text1.push_back(str);
	}
	for (int i = 0; i < N; i++){
		cin >> str;
		text2.push_back(str);
	}

	int count = 0;
	for (int i = 0; i < N; i++)
		solution(text1[i], text2[i], count);

	cout << count << endl;
}
