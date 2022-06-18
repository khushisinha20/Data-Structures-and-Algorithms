//leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateCombinations(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int start) {
        if (start >= candidates.size()) {
            if (target == 0)
                res.push_back(temp);
            return;
        }
        
        if (candidates[start] <= target) {
            temp.push_back(candidates[start]);
            generateCombinations(res, temp, candidates, target - candidates[start], start);
            temp.pop_back();
        }
        generateCombinations(res, temp, candidates, target, start + 1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        generateCombinations(res, temp, candidates, target, 0);
        return res;
    }
};