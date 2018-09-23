#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        unsigned i = 1;
        string res = "1";
        while (i < n){
            unsigned counter = 0;
            string temp;
            auto start = res.begin();
            for (auto c = res.begin(); c != res.end(); ++c){
                if (*start == *c)
                    counter++;
                else{
                    temp += to_string(counter) + *c;
                    counter = 1;
                    c++;
                }
            }
            temp += to_string(counter) + *start;
            res = temp;
            i++;
        }
        return res;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}