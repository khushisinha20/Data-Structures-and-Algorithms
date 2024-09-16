//leetcode.com/problems/valid-permutations-for-di-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int helper(string& s, vector<vector<int>>& dp, int currentValue, int position, vector<bool>& visited) {
        if (position >= s.length())
            return 1;

        if (dp[currentValue][position] != -1)
            return dp[currentValue][position];

        long long ans = 0;

        if (s[position] == 'I') {
            for (int j = currentValue + 1; j <= s.length(); ++j) {
                if (!visited[j]) {
                    visited[j] = true;
                    ans = (ans + helper(s, dp, j, position + 1, visited) % MOD) % MOD;
                    visited[j] = false;
                }
            }
        } else {
            for (int j = 0; j < currentValue; ++j) {
                if (!visited[j]) {
                    visited[j] = true;
                    ans = (ans + helper(s, dp, j, position + 1, visited) % MOD) % MOD;
                    visited[j] = false;
                }
            }
        }

        return dp[currentValue][position] = ans;
    }

    int numPermsDISequence(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        vector<bool> visited(n + 1, false);
        int ans = 0;

        for (int i = 0; i <= n; ++i) {
            visited[i] = true;
            ans = (ans + helper(s, dp, i, 0, visited) % MOD) % MOD;
            visited[i] = false;
        }

        return ans;
    }
};
