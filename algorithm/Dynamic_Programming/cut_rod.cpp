#include <iostream>
#include <algorithm>

using namespace std;

const int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int memoized_cut_rod_aux(const int price[], const int n, int memo[])
{
	if (memo[n] > 0)
		return memo[n];
	int q;
	if (n == 0)
		q = 0;
	else{
		q = -1;
		for (int i = 1; i <= n; ++i){
			q = max(q, price[i] + memoized_cut_rod_aux(price, n-i, memo));
		}
	}
	memo[n] = q;
	return q;
}

int memoized_cut_rod(const int price[], const int n)
{
	int memo[n+1];
	for (int i = 0; i < n+1; ++i){
		memo[i] = -1;
	}

	return memoized_cut_rod_aux(price, n, memo);
}

int bottom_up_cut_rod(const int price[], const int n)
{
	int r[n+1];
	r[0] = 0;
	for (int j = 1; j <= n; ++j){
		int q = -1;
		for (int i = 1; i <= j; ++i){
			q = max(q, price[i]+r[j-i]);
		}
		r[j] = q;
	}
	return r[n];
}

void extended_bottom_up_cut_rod(const int price[], const int n)
{
	int r[n+1], s[n+1];
	r[0] = 0;
	for (int j = 1; j <= n; ++j){
		int q = -1;
		for (int i = 1; i <= j; ++i){
			if (q < price[i] + r[j-i]){
				q = price[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

	cout << "the max value is " << r[n] << endl;
	int k = n;
	while (k > 0){
		cout << s[k] << " ";
		k = k - s[k];
	}
}

int main()
{
	//int max_value = bottom_up_cut_rod(price, 4);
	//cout << max_value << endl;
	extended_bottom_up_cut_rod(price, 4);
	return 0;
}
