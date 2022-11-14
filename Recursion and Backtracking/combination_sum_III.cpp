//leetcode.com/problems/combination-sum-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& combinations, vector<int>& currentCombination, int k, int currentNumber, int sum) {
        if (k == 0 && sum == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        
        if (k == 0)
            return;
        
        if (sum == 0)
            return;
        
        if (currentNumber == 10)
            return;
        
        currentCombination.push_back(currentNumber);
        backtrack(combinations, currentCombination, k - 1, currentNumber + 1, sum - currentNumber);
        currentCombination.pop_back();
        backtrack(combinations, currentCombination, k, currentNumber + 1, sum);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        backtrack(combinations, currentCombination, k, 1, n);
        return combinations;
    }
};