//leetcode.com/problems/lexicographically-smallest-string-after-adjacent-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isConsecutive(char a, char b) {
        return abs(a - b) == 1 or abs(a - b) == 25;
    }

    string lexicographicallySmallestString(string s) {
        int n = s.length();
        vector<vector<string>> dp(n + 1, vector<string> (n + 1, ""));

        for (int l = 0; l < n; ++l)
            dp[l][l] = string(1, s[l]);

        for (int l = n - 2; l >= 0; --l) {
            for (int r = l + 1; r <= n - 1; ++r) {
                string result = s[l] + dp[l + 1][r];
                for (int k = l + 1; k <= r; ++k) {
                    if (isConsecutive(s[l], s[k]) and dp[l + 1][k - 1] == "")
                        result = min(result, dp[k + 1][r]);
                }
                dp[l][r] = result;
            }
        }

        return dp[0][n - 1];
    }
};
