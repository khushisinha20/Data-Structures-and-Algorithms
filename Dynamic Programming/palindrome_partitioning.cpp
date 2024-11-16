//leetcode.com/problems/palindrome-partitioning-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string& s, vector<vector<int>>& dp, int left, int right) {
        if (left >= right)
            return true;

        if (dp[left][right] != -1)
            return dp[left][right];

        if (s[left] == s[right])
            return dp[left][right] = isPalindrome(s, dp, left + 1, right - 1);

        return dp[left][right] = false;
    }

    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                if (isPalindrome(s, dp, 0, i) and isPalindrome(s, dp, i + 1, j) and isPalindrome(s, dp, j + 1, n - 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
