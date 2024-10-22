//leetcode.com/problems/palindrome-partitioning-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostToPalindrome(string& s, int left, int right) {
        int changes = 0;

        while (left < right) {
            if (s[left] != s[right])
                ++changes;
            ++left;
            --right;
        }

        return changes;
    }

    int helper(string& s, int k, int index, vector<vector<int>>& dp) {
        int INF = 1000000000;

        if (k == 0)
            return index == s.length() ? 0 : INF;

        if (dp[index][k] != -1)
            return dp[index][k];

        int n = s.length();
        int result = INF;

        for (int i = index; i < n; ++i) {
            int cost = minCostToPalindrome(s, index, i);
            result = min(result, cost + helper(s, k - 1, i + 1, dp));
        }

        return dp[index][k] = result;
    }

    int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
        return helper(s, k, 0, dp);
    }
};

