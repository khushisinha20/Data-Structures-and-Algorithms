#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& combinations, vector<int>& currentCombination, int n, int k, int currentNumber) {
         if (k == 0) {
            combinations.push_back(currentCombination);
            return;
        }
        
        if (currentNumber > n)
            return;
        
        currentCombination.push_back(currentNumber);
        backtrack(combinations, currentCombination, n, k - 1, currentNumber + 1);
        currentCombination.pop_back();
        backtrack(combinations, currentCombination, n, k, currentNumber + 1);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        backtrack(combinations, currentCombination, n , k, 1);
        return combinations;
    }
};