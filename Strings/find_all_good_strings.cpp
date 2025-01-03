//leetcode.com/problems/find-all-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    vector<int> computeLPS(string& s) {
        int n = s.length();
        int i = 1;
        vector<int> lps(n, 0);
        int length = 0;

        while (i < n) {
            if (s[i] == s[length]) {
                lps[i] = ++length;
                ++i;
            } else {
                if (length != 0)
                    length = lps[length - 1];
                else
                    ++i;
            }
        }

        return lps;
    }

    int dfs(vector<vector<vector<vector<int>>>>& dp, string& s1, string& s2, string& evil, vector<int>& kmp, int pos, int kmpState, int tight1, int tight2) {
        int m = evil.length();
        int n = s1.length();

        if (kmpState == m)
            return 0;

        if (pos == n)
            return 1;

        if (dp[pos][kmpState][tight1][tight2] != -1)
            return dp[pos][kmpState][tight1][tight2];

        int result = 0;
        char low = tight1 ? s1[pos] : 'a';
        char high = tight2 ? s2[pos] : 'z';

        for (char c = low; c <= high; ++c) {
            int nextKmpState = kmpState;
            while (nextKmpState > 0 and evil[nextKmpState] != c)
                nextKmpState = kmp[nextKmpState - 1];
            if (evil[nextKmpState] == c)
                ++nextKmpState;
            result = (result + dfs(dp, s1, s2, evil, kmp, pos + 1, nextKmpState, tight1 && (low == c), tight2 && (high == c))) % MOD;
        }

        return dp[pos][kmpState][tight1][tight2] = result;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> kmp = computeLPS(evil);
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(evil.length(), vector<vector<int>>(2, vector<int>(2, -1))));
        return dfs(dp, s1, s2, evil, kmp, 0, 0, 1, 1);
    }
};

