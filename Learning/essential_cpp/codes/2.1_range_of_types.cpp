#include <iostream>
#include <limits>

using namespace std;

int main(){
	int max_int = numeric_limits<int>::max();
	int min_int = numeric_limits<int>::min();
	double max_db = numeric_limits<double>::max();
	double min_db = numeric_limits<double>::min();
	cout << max_int << endl;
	cout << min_int << endl;
	cout << max_db << endl;
	cout << min_db << endl;
	return 0;
}
