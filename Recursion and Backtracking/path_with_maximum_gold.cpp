//leetcode.com/problems/path-with-maximum-gold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max_gold = 0;
    void dfs(vector<vector<int>>& grid, int row, int col, int& total_gold) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return;
        
        int temp = grid[row][col];
        total_gold += temp;
        max_gold = max(max_gold, total_gold);
        grid[row][col] = 0;
        dfs(grid, row, col - 1, total_gold);
        dfs(grid, row, col + 1, total_gold);
        dfs(grid, row - 1, col, total_gold);
        dfs(grid, row + 1, col, total_gold);
        grid[row][col] = temp;
        total_gold -= temp;
        
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                int total_gold = 0;
                dfs(grid, row, col, total_gold);
            }
        }
        return max_gold;
    }
};