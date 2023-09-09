//leetcode.com/problems/decode-ways-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    
    long long countDecodings(string& s, vector<long long>& dp, int index) {
        if (index == s.length())
            return 1;
        
        if (dp[index] != -1)
            return dp[index];
        
        if (s[index] == '0')
            return 0;
        
        long long totalWays = 0;
        long long currentMultiplier = 1;
        
        if (s[index] == '*')
            currentMultiplier = 9;
        
        totalWays += currentMultiplier * countDecodings(s, dp, index + 1);
        int options = 0;
        
        if (index < s.length() - 1) {
            char nextChar = s[index + 1];
            
            if (s[index] == '*') {
                if (nextChar == '*') 
                    options = 15;
                else {
                    if (nextChar <= '6')
                        options = 2;
                    else
                        options = 1;
                }
            } else if (s[index] < '3') {
                if (nextChar == '*') {
                    if (s[index] == '1')
                        options = 9;
                    else
                        options = 6;
                } else {
                    if (stoi(s.substr(index, 2)) <= 26)
                        options = 1;
                }
            }
        }
        
        if (options)
            totalWays += options * countDecodings(s, dp, index + 2);
        
        return dp[index] = totalWays % MOD;
    }
    
    int numDecodings(string s) {
        vector<long long> dp(s.length(), -1);
        return countDecodings(s, dp, 0);
    }
};