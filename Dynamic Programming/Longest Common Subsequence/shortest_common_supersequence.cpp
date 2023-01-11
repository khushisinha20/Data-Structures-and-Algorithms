//leetcode.com/problems/shortest-common-supersequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void tabulate(vector<vector<int>>& dp, string& str1, string& str2) {
        for (int i = 0; i <= str1.size(); ++i) {
            for (int j = 0; j <= str2.size(); ++j) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.length() + 1, vector<int> (str2.length() + 1, -1));
        tabulate(dp, str1, str2);
        
        string scs;
        
        int i = str1.length();
        int j = str2.length();
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                scs.push_back(str1[i - 1]);
                --i;
                --j;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    scs.push_back(str1[i - 1]);
                    --i;
                } else {
                    scs.push_back(str2[j - 1]);
                    --j;
                }
            }
        }
        
        while (i > 0) {
            scs.push_back(str1[i - 1]);
            --i;
        }
        
        while (j > 0) {
            scs.push_back(str2[j - 1]);
            --j;
        }
        
        reverse(scs.begin(), scs.end());
        return scs;
    }
};