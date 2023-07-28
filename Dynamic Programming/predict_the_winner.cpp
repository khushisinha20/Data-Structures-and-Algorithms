//leetcode.com/problems/predict-the-winner/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int player1Score;
    int player2Score;
    
    int helper(vector<int>& nums, int left, int right, int turn) {
        if (left > right)
            return 0;
        
        if (dp[left][right][turn] != INT_MAX)
            return dp[left][right][turn];
        
        if (turn == 0) {
            int pickFromLeft = nums[left] + helper(nums, left + 1, right, !turn);
            int pickFromRight = nums[right] + helper(nums, left, right - 1, !turn);
            return dp[left][right][turn] = max(pickFromLeft, pickFromRight);
        } else {
            int pickFromLeft = helper(nums, left + 1, right, !turn);
            int pickFromRight = helper(nums, left, right - 1, !turn);
            return dp[left][right][turn] = min(pickFromLeft, pickFromRight);
        }
        
        return dp[left][right][turn] = INT_MAX;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(nums.size(), vector<vector<int>> (nums.size(), vector<int> (2, INT_MAX)));
        player1Score = helper(nums, 0, n - 1, 0);
        player2Score = accumulate(nums.begin(), nums.end(), 0) - player1Score;
        return player1Score >= player2Score;
    }
};