//leetcode.com/problems/last-stone-weight-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void possibleSubsetSum(vector<vector<bool>>& dp, int range, vector<int>& stones) {
        for (int i = 0; i < stones.size() + 1; ++i) {
            for (int j = 0; j < range + 1; ++j) {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else {
                    if (stones[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    
    int getMinimumDifference(vector<vector<bool>>& dp, int range, int size) {
        int minDiff = INT_MAX;
        for (int i = 0; i <= range / 2; ++i)
            if (dp[size][i])
                minDiff = min(minDiff, range - 2 * i);
        return minDiff;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        //minimum subset sum difference
        
        int range = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<bool>> dp(stones.size() + 1, vector<bool> (range + 1, false));
        possibleSubsetSum(dp, range, stones);
        return getMinimumDifference(dp, range, stones.size());
    }
};