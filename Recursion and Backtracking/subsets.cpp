//leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result, vector<int>& currentSubset) {
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }
        
        currentSubset.push_back(nums[index]);
        backtrack(nums, index + 1, result, currentSubset);
        currentSubset.pop_back();
        backtrack(nums, index + 1, result, currentSubset);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, result, currentSubset);
        return result;
    }
};