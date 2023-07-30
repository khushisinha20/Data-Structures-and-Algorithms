//leetcode.com/problems/strange-printer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    
    int helper(string& s, int left, int right) {
        if (left == right)
            return 1;
        
        if (left > right)
            return 0;
        
        if (dp[left][right] != -1)
            return dp[left][right];
        
        int i = left + 1;
        while (i <= right and s[i] == s[left])
            ++i;
        
        if (i == right + 1)
            return 1;
        
        int normalPrint = 1 + helper(s, i, right);
        
        int consecutivePrint = INT_MAX;
        
        for (int j = i; j <= right; ++j) {
            if (s[left] == s[j]) {
                int steps = helper(s, i, j - 1) + helper(s, j, right);
                consecutivePrint = min(consecutivePrint, steps);
            }
        }
        
        return dp[left][right] = min(normalPrint, consecutivePrint);
    }
    
    int strangePrinter(string s) {
        dp.resize(s.length() + 1, vector<int> (s.length() + 1, -1));
        return helper(s, 0, s.length() - 1);
    }
};