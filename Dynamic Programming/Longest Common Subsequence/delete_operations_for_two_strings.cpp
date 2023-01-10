//leetcode.com/problems/delete-operation-for-two-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& word1, string& word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, -1));
        
        for (int i = 0; i <= word1.length(); ++i) {
            for (int j = 0; j <= word2.length(); ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[word1.length()][word2.length()];
    }
    
    int deletionsFromWord(string& word, int& lcs) {
        return word.length() - lcs;
    }
    
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        int deletionsFromWord1 = deletionsFromWord(word1, lcs);
        int deletionsFromWord2 = deletionsFromWord(word2, lcs);
        return deletionsFromWord1 + deletionsFromWord2;
    }
};