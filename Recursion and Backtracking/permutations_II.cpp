//leetcode.com/problems/permutations-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& uniquePermutations) {
        if (index == nums.size()) {
            uniquePermutations.push_back(nums);
            return;
        }
        
        unordered_set<int> visited;
        
        for (int i = index; i < nums.size(); ++i) {
            if (visited.find(nums[i]) == visited.end()) {
                swap(nums[i], nums[index]);
                backtrack(nums, index + 1, uniquePermutations);
                swap(nums[i], nums[index]);
                visited.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> uniquePermutations;
        backtrack(nums, 0, uniquePermutations);
        return uniquePermutations;
    }
};