//leetcode.com/problems/ugly-number-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        
        int i2 = 1;
        int i3 = 1;
        int i5 = 1;
        
        for (int i = 2; i <= n; ++i) {
            int currentMultiplyBy2 = dp[i2] * 2;
            int currentMultiplyBy3 = dp[i3] * 3;
            int currentMultiplyBy5 = dp[i5] * 5;
            
            dp[i] = min({currentMultiplyBy2, currentMultiplyBy3, currentMultiplyBy5});
            
            if (dp[i] == currentMultiplyBy2)
                ++i2;
            
            if (dp[i] == currentMultiplyBy3)
                ++i3;
            
            if (dp[i] == currentMultiplyBy5)
                ++i5;
        }
        
        return dp[n];
    }
};