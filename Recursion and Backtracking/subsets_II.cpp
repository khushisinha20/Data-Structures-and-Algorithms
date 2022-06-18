//leetcode.com/problems/subsets-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsets(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int start) {
        result.push_back(temp);
        
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            
            temp.push_back(nums[i]);
            generateSubsets(result, temp, nums, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int> nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        generateSubsets(result, temp, nums, 0);
        return result;
    }
};