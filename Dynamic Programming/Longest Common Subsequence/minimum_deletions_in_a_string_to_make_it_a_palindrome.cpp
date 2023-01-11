//practice.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string& text1, string& text2) {
    vector<vector<int>> dp(text1.length() + 1, vector<int> (text2.length() + 1, -1));
    
    for (int i = 0; i < text1.length() + 1; ++i) {
        for (int j = 0; j < text2.length() + 1; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[text1.length()][text2.length()];
} 

int minDeletions(string str, int n) { 
    string reversedString = string(str.rbegin(), str.rend());
    int lcs = longestCommonSubsequence(str, reversedString);
    return str.length() - lcs;
} 