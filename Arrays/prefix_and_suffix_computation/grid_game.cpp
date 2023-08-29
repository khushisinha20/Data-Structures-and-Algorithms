//leetcode.com/problems/grid-game/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& row) {
        vector<long long> prefixSum(row.size(), 0); 
        prefixSum[0] = row[0];
        for (int i = 1; i < row.size(); ++i) 
            prefixSum[i] = (row[i] + prefixSum[i - 1]);
        return prefixSum;
    }
    
    long long gridGame(vector<vector<int>>& grid) {
        vector<long long> prefixSum1 = getPrefixSum(grid[0]);
        vector<long long> prefixSum2 = getPrefixSum(grid[1]);
        int n = grid[0].size();
        
        long long res = LLONG_MAX;
        long long secondRobotScore = 0;
        
        for (int i = 0; i < n; ++i) {
            long long top = prefixSum1.back() - prefixSum1[i]; 
            long long bottom = 0;
            if (i > 0)
                bottom = prefixSum2[i - 1];
            secondRobotScore = max(top, bottom);
            res = min(res, secondRobotScore);
        }
        
        return res;
    }
};
