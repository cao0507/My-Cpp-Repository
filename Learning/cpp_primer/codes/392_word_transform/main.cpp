#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

map<string, string> buildMap(ifstream& trans_rules){
    map<string, string> Map;
    string first_word, next_word;
    while (trans_rules >> first_word && getline(trans_rules, next_word)){
        Map[first_word] = next_word.substr(1);
    }
    return Map;
}

string transform1(string &word, map<string, string> trans_map){
    auto map_it = trans_map.find(word);
    if (map_it != trans_map.cend())
        return trans_map[word];
    return word;
}

void word_transform(ifstream& trans_rules, ifstream& text){
    auto trans_map = buildMap(trans_rules);
    string input;
    while(getline(text, input)){
        istringstream ss(input);
        string word;
        bool firstword = true;
        while (ss >> word){
            if (firstword)
                firstword = false;
            else
                cout << " ";

            cout << transform1(word, trans_map);
        }
        cout << endl;
    }
}

int main()
{
    ifstream trans_rules, text;
    trans_rules.open("trans_rules.txt");
    text.open("text.txt");

    word_transform(trans_rules, text);
    trans_rules.close();
    text.close();
    return 0;
}
