//leetcode.com/problems/string-compression-ii/

#include <bits/stdc++.h>
using namespace std;

int dp[101][27][101][101];

class Solution {
public:
    int helper(string& s, int index, int previous, int frequency, int k) {
        if (k < 0)
            return INT_MAX;
        
        if (index >= s.length())
            return 0;
        
        if (dp[index][previous][frequency][k] != -1)
            return dp[index][previous][frequency][k];
        
        int deleteCharacter = helper(s, index + 1, previous, frequency, k - 1);
        int keepCharacter = 0;
        
        if (s[index] - 'a' == previous) {
            int oneMoreAdded = 0;
            if (frequency == 1 or frequency == 9 or frequency == 99)
                oneMoreAdded = 1;
            keepCharacter = oneMoreAdded + helper(s, index + 1, previous, frequency + 1, k);
        } else
            keepCharacter = 1 + helper(s, index + 1, s[index] - 'a', 1, k);
        
        return dp[index][previous][frequency][k] = min(keepCharacter, deleteCharacter);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return helper(s, 0, 26, 0, k);
    }
};