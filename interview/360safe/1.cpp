#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int string2int(string str) {
	int res = 0;
	bool isDot = false;
	int flag = 1;
	size_t i = 0;
	if (str.empty())
		return 0;
	if (str[0] == '-'){
		flag = -1;
		i = 1;
	}
	else if (str[0] == '+')
		i = 1;

	for (; i < str.size(); i++){
		if (isDot == false){
			if (str[i] == '.')
				isDot = true;
			else if (str[i] < '0' || str[i] > '9')
				return 0;
			else
				res = res*10 + str[i] - '0';
		}
		else{
			if (str[i] < '0' || str[i] > '9')
				return 0;
		}
	}
	return res*flag;
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _str;
    getline(cin, _str);
    
    res = string2int(_str);
    cout << res << endl;
    
    return 0;

}
