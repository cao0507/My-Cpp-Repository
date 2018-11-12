#include <iostream>
#include <string>

using namespace std;

string getanswer(int N) {
    string ans = "1";
    int i = 0;
    while (i < N){
        int c_in = 0;
        for (int j = ans.size()-1; j >= 0; --j){
            int temp = 2*(ans[j] - '0') + c_in;
            ans[j] = temp%10 + '0';
            c_in = temp/10;
        }
        if (c_in != 0)
            ans.insert(ans.begin(), c_in + '0');
        ++i;
    }
    return ans;
}

int main() {
    int N;
    while (cin >> N) {
        string ans;
        ans = getanswer(N);
        cout << ans <<endl;
    }
}
