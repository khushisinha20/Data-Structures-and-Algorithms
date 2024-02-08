//leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    long long int helper(int n, int x, int last, vector<vector<int>>& dp) {
        if (n < 0)
            return 0;
        
        if (n == 0)
            return 1;
        
        int power = pow(last, x);

        if (power > n)
            return 0;
        
        if (dp[n][last] != -1)
            return dp[n][last];

        long long int take = helper(n - power, x, last + 1, dp);
        long long int notTake = helper(n, x, last + 1, dp);
        long long int ways = (take % MOD + notTake % MOD) % MOD;

        return dp[n][last] = ways;
    }

    int numberOfWays(int n, int x) {
        int last = 1; 
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return static_cast<int>(helper(n, x, last, dp));
    }
};