//leetcode.com/problems/champagne-tower/

#include <bits/stdc++.h>
using namespace std;

/*
class Solution {
public:
    double helper(double poured, int row, int glass, vector<vector<double>>& dp) {
        if (glass < 0 || glass > row || poured == 0.0)
            return 0.0;
        
        if (dp[row][glass] != -1.0)
            return dp[row][glass];
        
        double leftFall = max(0.0, helper(poured - 1, row - 1, glass - 1, dp) - 1) / 2.0;
        double rightFall = max(0.0, helper(poured - 1, row - 1, glass, dp) - 1) / 2.0;
        
        return dp[row][glass] = leftFall + rightFall;
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, -1.0));
        dp[0][0] = poured;
        
        return min(1.0, helper(poured, query_row, query_glass, dp));
    }
};
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double> (101, 0));
        dp[0][0] = poured;
        
        for (int row = 0; row <= query_row; ++row) {
            for (int glass = 0; glass <= query_glass; ++glass) {
                double overflow = (dp[row][glass] - 1) / 2.0;
                if (overflow > 0) {
                    dp[row + 1][glass] += overflow;
                    dp[row + 1][glass + 1] += overflow;
                }
            }
        }
        
        return min(1.0, dp[query_row][query_glass]);
    }
};

