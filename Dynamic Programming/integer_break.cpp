//leetcode.com/problems/integer-break/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& dp, int n) {
        if (n == 1)
            return 1;
        
        if (dp[n] != -1)
            return dp[n];
        
        int maxProduct = 0;
        for (int i = 1; i < n; ++i) {
            int notBreakValue = i * (n - i);
            int breakValue = i * helper(dp, n - i);
            maxProduct = max(maxProduct, max(notBreakValue, breakValue));
        }
        
        return dp[n] = maxProduct;
    }
    
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};