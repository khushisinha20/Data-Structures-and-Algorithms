//leetcode.com/problems/delete-columns-to-make-sorted-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletionsSizeHelper(vector<string>& strs, int currentIndex, int previousIndex, vector<vector<int>>& dp) {
        int totalCols = strs[0].size();
        int totalRows = strs.size();

        if (currentIndex == totalCols)
            return 0;

        if (dp[currentIndex][previousIndex + 1] != -1)
            return dp[currentIndex][previousIndex + 1];

        int ans = INT_MAX;
        bool canKeep = true;

        if (previousIndex != -1) {
            for (int row = 0; row < totalRows; ++row) {
                if (strs[row][previousIndex] > strs[row][currentIndex]) {
                    canKeep = false;
                    break;
                }
            }
        }

        if (canKeep)
            ans = min(ans, minDeletionsSizeHelper(strs, currentIndex + 1, currentIndex, dp));

        ans = min(ans, 1 + minDeletionsSizeHelper(strs, currentIndex + 1, previousIndex, dp));

        return dp[currentIndex][previousIndex + 1] = ans;
    }

    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<vector<int>> dp(m, vector<int>(m + 1, -1));

        return minDeletionsSizeHelper(strs, 0, -1, dp);
    }
};
