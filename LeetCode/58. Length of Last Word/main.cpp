#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        for (auto c = s.begin(); c != s.end(); ++c)
            cout << *c;
        cout << endl;
        int len = 0;
        if (s.empty())
            return 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == ' ' && len == 0)
                continue;
            if (s[i] == ' ' && len != 0)
                break;
            if (s[i] != ' ')
                len++;
        }
        return len;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLastWord(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
