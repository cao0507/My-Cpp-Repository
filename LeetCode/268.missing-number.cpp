/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums){
            sum += num;
        }
        return (n + 1)*n/2 - sum;
    }
};

