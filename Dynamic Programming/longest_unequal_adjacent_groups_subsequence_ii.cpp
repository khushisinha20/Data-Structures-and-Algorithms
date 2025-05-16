//leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool differByOneChar(string word1, string word2) {
        if (word1.length() != word2.length())
            return false;
        int diffCount = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i])
                ++diffCount;
            if (diffCount > 1)
                return false;
        }
        return diffCount == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxLength = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] &&
                    differByOneChar(words[i], words[j]) &&
                    dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLength) {
                maxLength = dp[i];
                lastIndex = i;
            }
        }

        vector<string> result;
        while (lastIndex != -1) {
            result.push_back(words[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

