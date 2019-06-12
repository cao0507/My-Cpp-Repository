#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, temp;
    vector<int> re(3, 0);
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> temp;
        re[temp%3]++;
    }
    long long ans = 0;
    ans += (long long)re[0]*(re[0]-1)/2;
    ans += (long long)re[1]*re[2];
    cout << ans << endl;
}
