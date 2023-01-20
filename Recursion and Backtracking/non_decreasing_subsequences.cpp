//leetcode.com/problems/non-decreasing-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& currentSequence, set<vector<int>>& distinctSubsequences, int index) {
        if (index == nums.size()) {
            if (currentSequence.size() > 1)
                distinctSubsequences.insert(currentSequence);
            return;
        }
        
        if (currentSequence.empty() || nums[index] >= currentSequence.back()) {
            currentSequence.push_back(nums[index]);
            backtrack(nums, currentSequence, distinctSubsequences, index + 1);
            currentSequence.pop_back();
        }
        backtrack(nums, currentSequence, distinctSubsequences, index + 1);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> currentSequence;
        set<vector<int>> distinctSubsequences;
        
        backtrack(nums, currentSequence, distinctSubsequences, 0);
        
        vector<vector<int>> subsequences;
        
        for (auto subsequence: distinctSubsequences)
            subsequences.push_back(subsequence);
        
        return subsequences;
    }
};