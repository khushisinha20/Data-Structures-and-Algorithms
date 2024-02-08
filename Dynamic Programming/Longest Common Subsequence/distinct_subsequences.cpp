//leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    int numDistinct(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        vector<vector<double>> dp(sLength + 1, vector<double> (tLength + 1, 0));
        
        for (int i = 0; i <= sLength; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i <= sLength; ++i) {
            for (int j = 1; j <= tLength; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return (int)dp[sLength][tLength];
    }
};
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();
        vector<vector<double>> dp(sLength + 1, vector<double> (tLength + 1, 0));
        
        for (int i = 0; i <= sLength; ++i)
            dp[i][0] = 1;
        
        for (int i = 1; i <= sLength; ++i) {
            for (int j = 1; j <= tLength; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return (int)dp[sLength][tLength];
    }
};