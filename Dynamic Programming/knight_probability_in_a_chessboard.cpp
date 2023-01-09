//leetcode.com/problems/knight-probability-in-chessboard/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<double, double>> directions = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    double dp[26][26][101] = {{{0}}};
    
    double helper(int n, int k, int row, int column) {
        if (row < 0 || row >= n || column < 0 || column >= n)
            return 0;
        
        if (k == 0)
            return 1;
        
        if (dp[row][column][k])
            return dp[row][column][k];
        
        double sum = 0;
        for (auto direction: directions) 
            sum += helper(n, k - 1, row + direction.first, column + direction.second);
        
        return dp[row][column][k] = sum / 8.0;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        return helper(n, k, row, column);
    }
};