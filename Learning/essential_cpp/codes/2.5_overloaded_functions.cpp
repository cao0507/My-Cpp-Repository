#include <iostream>
#include <vector>
#include <string>
//#include <climits>

using namespace std;

int max(int v1, int v2){
	if (v1 > v2)
		return v1;
	else
		return v2;
}

float max(float f1, float f2){
	if (f1 > f2)
		return f1;
	else
		return f2;
}

string max(string s1, string s2){
	if (s1 > s2){
		return s1;
	}
	else{
		return s2;
	}	
}

int max(vector<int> &vec){
	int max = vec.front();
	for (auto &v:vec){
		if (v > max)
			max = v;
	}
	return max;
}

float max(vector<float> &vec){
	float max = vec.front();
	for (auto &v:vec){
		if (v > max)
			max = v;
	}
	return max;
}

string max(vector<string> &vec){
	string max = vec.front();
	for (auto &v:vec){
		if (v > max)
			max = v;
	}
	return max;
}

int max(int a[], int size){
	int max = a[0];
	for (int i = 0; i < size; ++i){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

float max(float a[], int size){
	float max = a[0];
	for (int i = 0; i < size; ++i){
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

string max(string a[], int size){
	string max = a[0];
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

	int m1 = max(v1, v2);
	float m2 = max(f1, f2);
	string m3 = max(s1, s2);
	cout << "1 > 2: " << m1 << endl;
	cout << "1.1 > 2.3: " << m2 << endl;
	cout << "aa > bb: " << m3 << endl;

	vector<int> vec = {3, 4, 8, 2, 6};
	cout << "{3, 4, 8, 2, 6}: " << max(vec) << endl;

	vector<float> vec2 = {3.1, 4.1, 8.1};
	cout << "{3.1, 4.1, 8.1}: " << max(vec2) << endl;

	vector<string> vec3 = {"bb", "cc", "aa", "ee"};
	cout << "{\"bb\", \"cc\", \"aa\", \"ee\"}: " << max(vec3) << endl;

	int a[3] = {1, 3, 2};
	float b[3] = {1.1, 3.1, 2.1};
	string c[3] = {"bb", "cc", "aa"};
	cout << max(a, 3) << endl;
	cout << max(b, 3) << endl;
	cout << max(c, 3) << endl;

	return 0;
}
