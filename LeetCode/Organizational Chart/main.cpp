#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct org_div {
    string Parent_division;
    int Size1;
    int Size2;
    org_div(string str, int m, int n): Parent_division(str), Size1(m), Size2(n) {}
};

int main() {
    int N, Q;
    cin >> N >> Q;
    map<string, struct org_div> org;
    //vector<string, int> query;
    int i = 1;
    while (i <= N){
        string division_name, parent_division;
        int size1, size2;
        cin >> division_name >> parent_division >> size1 >> size2;
        //struct org_div Division;
        org[division_name] = new org_div(parent_division, size1, size2);
        //org[division_name] = new divison(parent_division, size1, size2);
    }
    /*i = 1;
    while (i <= Q){
        string division_name;
        int type;
        cin >> division_name >> type;
        int size1 = arg[division_name].Size1;
        int size2 = arg[division_name].Size2;
        if (type ==1 && size1 != 0)
            cout << size1 << size1 << endl;
        else if (type == 2 && size2 != 0)
            cout << size2 << size2 << endl;
    } */

    return 0;

}
