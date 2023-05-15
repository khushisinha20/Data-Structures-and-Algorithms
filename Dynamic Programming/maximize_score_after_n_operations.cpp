//leetcode.com/problems/maximize-score-after-n-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, vector<bool>& visited, int operation, unordered_map<vector<bool>, int>& dp) {
        int maxScore = 0;
        int n = nums.size();
        
        if (dp.find(visited) != dp.end())
            return dp[visited];
        
        for (int i = 0; i < n - 1; ++i) {
            if (visited[i])
                continue;
            for (int j = i + 1; j < n; ++j) {
                if (visited[j])
                    continue;
                
                visited[i] = true;
                visited[j] = true;
                
                int currentScore = operation * __gcd(nums[i], nums[j]);
                int remainingScore = helper(nums, visited, operation + 1, dp);
                maxScore = max(maxScore, currentScore + remainingScore);
                
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return dp[visited] = maxScore;
    }
    
    int maxScore(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        unordered_map<vector<bool>, int> dp;
        return helper(nums, visited, 1, dp);
    }
};