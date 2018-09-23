#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        unsigned counter = 0;
        auto start = chars.begin(), next = chars.begin();
        while(next != chars.end()){
            if (*start == *next)
                counter++;
            else{
                if (counter >= 2){
                    int i = 1;
                    for (auto c:to_string(counter)){
                        *(start + i) = c;
                        i++;
                    }
                    while(i < counter){
                        chars.erase(start + i);
                        i++;
                    }
                }
                start = next;
                counter = 1;
            }
            next++;
        }
        if (counter >= 2){
            int i = 1;
            for (auto c:to_string(counter)){
                *(start + i) = c;
                i++;
            }
            while(i < counter){
                chars.erase(start + i);
                i++;
            }
        }
        return chars.size();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
