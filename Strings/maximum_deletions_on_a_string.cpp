//leetcode.com/problems/maximum-deletions-on-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteString(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int len = 1; i + 2 * len <= n; ++len) {
                if (s.compare(i, len, s, i + len, len) == 0) {
                    dp[i] = max(dp[i], 1 + dp[i + len]);
                }
            }
        }

        return dp[0];
    }
};
