#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> &pushV, vector<int> &popV){
        stack<int> S;
        int poped = 0, poping = 0;
        while ( poped < pushV.size() ){
            if (poping < pushV.size())
                S.push(pushV[poping]);
            else if (S.top() != popV[poped])
                return false;

            if (S.top() == popV[poped]){
                S.pop();
                poped++;
            }
            poping++;
        }
        return true;
    }
};

void Test(const string &test, vector<int> &v1, vector<int> &v2){
    Solution s;
    cout << test << " ";
    if (s.IsPopOrder(v1, v2))
        cout << "passed.\n";
    else
        cout << "failed.\n";
}

void Test1()
{
    int pu[] = {1, 2, 3, 4, 5};
    int po[] = {4, 5, 3, 2, 1};
    vector<int> push(pu, pu+5);
    vector<int> pop(po, po+5);

    Test("Test1", push, pop);
}

int main(){
    Test1();
    return 0;
}
