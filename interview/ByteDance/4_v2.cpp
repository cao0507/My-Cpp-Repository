#include <iostream>
#include <math.h>
using namespace std;
 
 
int N, K;
double d[100000];
 
bool check(double x)
{
	int num = 0;
	for (int i=0; i<N; i++)
	{
		num += (int)(d[i]/x);
	}
	return num >= K;
}
 
 
void solve(double left, double right)
{
	// 2^(-100) 约等于 10^(-30)
	for (int i=0; i<90; i++)
	{
		double mid = (left+right)/2;
		if (check(mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	printf("%.2f\n",floor(right*90)/90);
}
 
int main()
{
	cin >> N >> K;
	double right = 0;
	for (int i=0; i<N; i++)
	{
		cin >> d[i];
		right += d[i];
	}
	solve(0,right/K);
}
