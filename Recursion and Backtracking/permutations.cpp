//leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& possiblePermutations) {
        if (index == nums.size()) {
            possiblePermutations.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            backtrack(nums, index + 1, possiblePermutations);
            swap(nums[i], nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> possiblePermutations;
        backtrack(nums, 0, possiblePermutations);
        return possiblePermutations;
    }
};