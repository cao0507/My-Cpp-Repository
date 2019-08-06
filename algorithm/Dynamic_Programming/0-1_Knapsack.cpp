#include <iostream>
#include <algorithm>

using namespace std;

typedef struct commodity
{
    int value;
    int weight;
}commodity;

const int N = 3;
const int W = 50;

commodity goods[N] = {{60, 10}, {100, 20}, {120, 30}};
int dp[N+1][W+1];

int solution(commodity* goods)
{
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;

    for (int j = 1; j <= W; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= W; ++j){
            if (goods[i].weight <= j){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-goods[i].weight]+goods[i].value);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

int main()
{
    int ans = solution(goods);
    cout << ans << endl;
    return 0;
}
