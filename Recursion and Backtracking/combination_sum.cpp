//leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& combinations, int index) {
        if (index == candidates.size())
            return;
        
        if (target < 0)
            return;
        
        if (target == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        
        currentCombination.push_back(candidates[index]);
        backtrack(candidates, target - candidates[index], currentCombination, combinations, index);
        currentCombination.pop_back();
        backtrack(candidates, target, currentCombination, combinations, index + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        backtrack(candidates, target, currentCombination, combinations, 0);
        return combinations;
    }
};