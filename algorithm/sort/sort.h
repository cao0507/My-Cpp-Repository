#include <vector>

using namespace std;

class sort{
public:
	void swap(int &a, int &b);
	void print(const vector<int> &nums);
};

class Bubble_sort:public sort{
public:
	void bubble_sort(vector<int> &nums);
};

class Quick_sort:public sort{
public:
	void quick_sort(vector<int> &nums);

private:
	void _quick_sort(vector<int> &nums, int p, int r);
	int _partition(vector<int> &nums, int p, int r);
};
