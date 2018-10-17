#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = 0, counter = 1;
        chars[len++] = chars[0];
        auto p1 = chars.begin();
        for (auto p2 = p1 + 1; p2 != chars.end(); p2++){
            if (*p1 == *p2)
                counter++;
            else{

                if (counter > 1)
                    for (auto c:to_string(counter))
                        chars[len++] = c;
                p1 = p2;
                chars[len++] = *p1;
                counter = 1;
            }
        }
        if (counter > 1)
            for (auto c:to_string(counter))
                chars[len++] = c;
        chars.resize(len);
        return len;
    }
};

vector<char> stringToCharVector(string input){
    vector<char> output;

}

int main()
{
    string line;
    while (getline(cin, line)){
        vector<char> chars = stringToCharVector(line);
        int ret = Solution().compress(chars);

        cout << "vector<char> chars = " << endl;
        for (auto c:chars)
            cout << c;
        cout << endl;
        cout << "The length of chars is: " << ret << endl;
    }
}
