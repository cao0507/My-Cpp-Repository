#include <iostream>
#include <vector>

using namespace std;

class Point
{
public:
    Point(){
        cout << "construction" << endl;
    }

    Point(const Point& p){
        cout << "copy construction" << endl;
    }
    
    ~Point(){
        cout << "destruction" << endl;
    }
};

int main()
{
    vector<Point> pointVec;
    Point a;
    Point b;
    pointVec.push_back(a);
    pointVec.push_back(b);

    cout << pointVec.size() << endl;
    return 0;
}