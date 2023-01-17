//leetcode.com/problems/flip-string-to-monotone-increasing/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int> (2, -1));
        
        int n = s.length();
        
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j < 2; ++j) {
                if (i == n)
                    dp[i][j] = 0;
                else if (s[i] == '0') {
                    if (j == 0) 
                        dp[i][j] = min(1 + dp[i + 1][1], dp[i + 1][0]);
                    else 
                        dp[i][j] = 1 + dp[i + 1][1];
                } else {
                    if (j == 0) 
                        dp[i][j] = min(dp[i + 1][1], 1 + dp[i + 1][0]);
                    else 
                        dp[i][j] = dp[i + 1][1];
                }
            }
        }
        
        return dp[0][0];
    }
};