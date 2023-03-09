//leetcode.com/problems/student-attendance-record-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    
    int helper(int n, int absent, int late, vector<vector<vector<int>>>& dp) {
        if (n == 0)
            return 1;
        
        if (dp[n][absent][late] != -1)
            return dp[n][absent][late];
        
        int presentPossibility = 0;
        int absentPossibility = 0;
        int latePossibility = 0;
        
        if (absent > 0)
            absentPossibility = helper(n - 1, absent - 1, 2, dp) % MOD;
        
        if (late > 0)
            latePossibility = helper(n - 1, absent, late - 1, dp) % MOD;
        
        presentPossibility = helper(n - 1, absent, 2, dp) % MOD;
        
        return dp[n][absent][late] = ((latePossibility + absentPossibility) % MOD + presentPossibility) % MOD;
    }
    
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));
        return helper(n, 1, 2, dp);
    }
}