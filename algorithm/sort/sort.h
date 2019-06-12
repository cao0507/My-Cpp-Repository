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

class Merge_sort:public sort{
public:
	void merge_sort(vector<int> &nums);

private:
	void _merge_sort(vector<int> &nums, int begin, int end);
	void _merge(vector<int> &nums, int begin, int mid, int end);
};

class Insert_sort:public sort{
public:
	void insert_sort(vector<int> &nums);
};

class Select_sort:public sort{
public:
	void select_sort(vector<int> &nums);
};

class Heap_sort:public sort{
public:
	void heap_sort(vector<int> &nums);

private:
	void build_heap(vector<int> &nums);
	void heapify(vector<int> &nums, int i, int heap_size);
};
