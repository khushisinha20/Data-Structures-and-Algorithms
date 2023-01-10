//practice.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        int dp[n + 1][m + 1] = {{-1}};
        int length = 0;
        
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < m + 1; ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    length = max(dp[i][j], length);
                } else
                    dp[i][j] = 0;
            }
        }
        return length;
    }
};