//leetcode.com/problems/combination-sum-ii/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& candidates, int target,  vector<vector<int>>& combinations, vector<int>& currentCombination, int index) {
       if (target == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] > target)
                break;
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], combinations, currentCombination, i + 1);
            currentCombination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        backtrack(candidates, target, combinations, currentCombination, 0);
        return combinations;
    }
};