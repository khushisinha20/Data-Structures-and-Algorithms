//leetcode.com/problems/number-of-ways-of-cutting-a-pizza/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> dp;
    int MOD = 1000000007;
    
    int helper(vector<string>& pizza, vector<vector<int>>& apples, int& ROWS, int& COLS, int row, int col, int k) {
        if (apples[row][col] < k)
            return 0;
        
        if (k == 1) 
            return apples[row][col] >= 1 ? 1 : 0;
        
        if (dp[row][col][k] != -1)
            return dp[row][col][k];
        
        long long currentWays = 0;
        
        for (int i = row + 1; i < ROWS; ++i) {
            if (apples[row][col] - apples[i][col] > 0 and apples[i][col] >= k - 1) 
                currentWays += helper(pizza, apples, ROWS, COLS, i, col, k - 1) % MOD;
        }
            
        for (int j = col + 1; j < COLS; ++j) {
            if (apples[row][col] - apples[row][j] > 0 and apples[row][j] >= k - 1)
                currentWays += helper(pizza, apples, ROWS, COLS, row, j, k - 1) % MOD;
        }
        
        return dp[row][col][k] = currentWays % MOD;
    }
    
    int ways(vector<string>& pizza, int k) {
        int ROWS = pizza.size();
        int COLS = pizza[0].size();
        
        vector<vector<int>> apples(ROWS + 1, vector<int> (COLS + 1, 0));
        for (int i = ROWS - 1; i >= 0 ; --i)
            for (int j = COLS - 1; j >= 0; --j)
                apples[i][j] = apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
        
        
        dp.resize(ROWS + 1, vector<vector<int>> (COLS + 1, vector<int> (k + 1, -1)));
        return helper(pizza, apples, ROWS, COLS, 0, 0, k);
    }
};