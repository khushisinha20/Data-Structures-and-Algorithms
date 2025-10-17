//leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(string& s, int k, int index, int mask, bool changed, unordered_map<long long, int>& dp) {
        int n = s.length();

        if (index == n)
            return 1;

        long long key = ((long long)index << 32) | ((long long)mask << 1) | changed;
        if (dp.count(key))
            return dp[key];

        int result = 0;
        int bit = 1 << (s[index] - 'a');
        int newMask = mask | bit;

        if (__builtin_popcount(newMask) > k)
            result = 1 + dfs(s, k, index + 1, bit, changed, dp);
        else
            result = dfs(s, k, index + 1, newMask, changed, dp);

        if (!changed) {
            for (int c = 0; c < 26; ++c) {
                if (c == s[index] - 'a')
                    continue;
                int newBit = 1 << c;
                int newMask = mask | newBit;
                if (__builtin_popcount(newMask) > k) {
                    result = max(result, 1 + dfs(s, k, index + 1, newBit, true, dp));
                } else {
                    result = max(result, dfs(s, k, index + 1, newMask, true, dp));
                }
            }
        }

        return dp[key] = result;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> dp;
        return dfs(s, k, 0, 0, false, dp);
    }
};

