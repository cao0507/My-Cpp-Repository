#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
	cin >> N >> M;
    vector<long long> vec(N, 0);
    long long max_value = 0, tot = 0;
    for(auto &val : vec) {
		cin >> val;
        val *= 1000;
        max_value = max(max_value, val);
        tot += val;
    }
    if(tot < M)
		cout << "0.00\n";
    else {
        long long p = 1, q = max_value + 1;
        int tmp = 0;
        while(p < q) {
            long long mid = (p + q) >> 1;
            tmp = 0;
            for(auto val : vec)
                tmp += val / mid;
            if(tmp >= M)
                p = mid + 1;
            else q = mid;
        }
        if(tmp < M) --p;
		cout << fixed << setprecision(2) << p/1000.0 << endl;
    }
    return 0;
}
