//leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsets(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int start) {
        if (start >= nums.size()) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[start]);
        generateSubsets(result, temp, nums, start + 1);
        temp.pop_back();
        generateSubsets(result, temp, nums, start + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        generateSubsets(result, temp, nums, 0);
        return result;
    }
};