//leetcode.com/problems/beautiful-arrangement/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, int index, int& res) {
        if (index == nums.size()) {
            ++res;
            return;
        }
        
        for (int i = index; i < nums.size(); ++i) {
            if (nums[i] % (index + 1) == 0 || (index + 1) % nums[i] == 0) {
                swap(nums[i], nums[index]);
                helper(nums, index + 1, res);
                swap(nums[index], nums[i]);
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> nums;
        for (int i = 1; i < n + 1; ++i)
            nums.emplace_back(i);
        int res = 0;
        helper(nums, 0, res);
        return res;
    }
};