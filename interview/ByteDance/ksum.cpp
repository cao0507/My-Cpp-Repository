#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> ksum(vector<int>& nums, int target, int k, int index){
    vector<vector<int> > res;
    if (index >= 9)
        return res;
    if (k == 2){
        int i = index, j = 8;
        while (i < j) {
            if (target - nums[i] == nums[j]){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                res.push_back(temp);
                i++;
                j--;
            }
            else if (target - nums[i] > nums[j])
                i++;
            else
                j--;
        }
    }
    else{
        for (int i = index; i < 10 - k; i++){
            vector<vector<int> > temp = ksum(nums, target - nums[i], k-1, i+1);
            if (!temp.empty()){
                for (int j = 0; j < temp.size(); j++){
                    temp[j].insert(temp[j].begin(), nums[i]);
                    res.push_back(temp[j]);
                }
            }
        }
    }
    return res;
}

int main(){
    int k, x;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cin >> k >> x;
    if (k * (k + 1)/2 > x || k * (9 + 9-k+1)/2 < x)
        return 0;
    if (k == 1)
        cout << nums[x] << endl;
    vector<vector<int> > res = ksum(nums, x, k, 0);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
