//leetcode.com/problems/reducing-dishes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& dp, int index, vector<int>& satisfaction, int position) {
        if (index >= satisfaction.size())
            return 0;
        
        if (dp[index][position] != -1)
            return dp[index][position];
        
        int pick = position * satisfaction[index] + helper(dp, index + 1, satisfaction, position + 1);
        int notPick = helper(dp, index + 1, satisfaction, position);
        
        return dp[index][position] = max(pick, notPick);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(501, vector<int> (501, -1));
        int position = 1;
        return helper(dp, 0, satisfaction, position);
    }
};