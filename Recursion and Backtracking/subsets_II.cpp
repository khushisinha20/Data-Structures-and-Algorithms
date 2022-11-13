//leetcode.com/problems/subsets-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int currentPosition, vector<int>& currentSubset, vector<vector<int>>& result) {
        if (currentPosition == nums.size()) {
            result.push_back(currentSubset);
            return;
        }
        
        currentSubset.push_back(nums[currentPosition]);
        backtrack(nums, currentPosition + 1, currentSubset, result);
        currentSubset.pop_back();
        while (currentPosition + 1 < nums.size() && nums[currentPosition] == nums[currentPosition + 1])
            ++currentPosition;
        backtrack(nums, currentPosition + 1, currentSubset, result);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }
};