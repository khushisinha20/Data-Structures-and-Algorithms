//leetcode.com/problems/stone-game-iv/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    bool canWin(int n, vector<int>& dp) {
        if (n == 0)
            return false;
        
        if (dp[n] != -1)
            return dp[n];
        
        for (int i = 1; i * i <= n; ++i) {
            if (!canWin(n - i * i, dp)) {
                return dp[n] = true;
            }
        }
        
        return dp[n] = false;
    }
    
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return canWin(n, dp);
    }
};
*/

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};