#include <iostream>
#include <vector>
#include <string>
//#include <climits>

using namespace std;

template <typename elemType>
elemType Max(elemType v1, elemType v2){
	if (v1 > v2)
		return v1;
	else
		return v2;
}

template <typename elemType>
elemType Max(vector<elemType> &vec){
	elemType max = vec.front();
	for (auto &v:vec){
		if (v > max)
			max = v;
	}
	return max;
}

template <typename elemType>
elemType Max(elemType a[], int size){
	elemType max = a[0];
	for (int i = 0; i < size; ++i){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main(){
	int v1 = 1, v2 = 2;
	float f1 = 1.1, f2 = 2.3;
	string s1 = "aa", s2 = "bb";

	int m1 = Max(v1, v2);
	float m2 = Max(f1, f2);
	string m3 = Max(s1, s2);
	cout << "1 > 2: " << m1 << endl;
	cout << "1.1 > 2.3: " << m2 << endl;
	cout << "aa > bb: " << m3 << endl;

	vector<int> vec = {3, 4, 8, 2, 6};
	cout << "{3, 4, 8, 2, 6}: " << Max(vec) << endl;

	vector<float> vec2 = {3.1, 4.1, 8.1};
	cout << "{3.1, 4.1, 8.1}: " << Max(vec2) << endl;

	vector<string> vec3 = {"bb", "cc", "aa", "ee"};
	cout << "{\"bb\", \"cc\", \"aa\", \"ee\"}: " << Max(vec3) << endl;

	int a[3] = {1, 3, 2};
	float b[3] = {1.1, 3.1, 2.1};
	string c[3] = {"bb", "cc", "aa"};
	cout << Max(a, 3) << endl;
	cout << Max(b, 3) << endl;
	cout << Max(c, 3) << endl;

	return 0;
}
