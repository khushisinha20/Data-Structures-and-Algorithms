//leetcode.com/problems/longest-ideal-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& dp, int index, int previous, string& s, int& k) {
        if (index == s.length())
            return 0;
        
        if (dp[index][previous] != -1)
            return dp[index][previous];
        
        int take = 0;
        char current = s[index] - 'a' + 1;
        
        if (previous == 0 or abs(previous - current) <= k)
            take = helper(dp, index + 1, current, s, k) + 1;
        
        int notTake = helper(dp, index + 1, previous, s, k);
        
        return dp[index][previous] = max(take, notTake);
    }
    
    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int> (27, -1));
        return helper(dp, 0, 0, s, k);
    }
};