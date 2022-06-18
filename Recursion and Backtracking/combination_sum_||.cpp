//leetcode.com/problems/combination-sum-ii/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateCombinations(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i - 1] == candidates[i])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            generateCombinations(res, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generateCombinations(res, temp, candidates, target, 0);
        return res;
    }
};
