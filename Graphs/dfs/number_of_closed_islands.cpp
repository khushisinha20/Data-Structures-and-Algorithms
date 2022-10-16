//leetcode.com/problems/number-of-closed-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col])
            return;
        
        grid[row][col] = 1;
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
    
    void visitUnclosedIslands(vector<vector<int>>& grid) {
        int lastRow = grid.size() - 1;
        int lastCol = grid[0].size() - 1;
        for (int i = 0; i < grid.size(); ++i) {
            if (grid[i][lastCol] == 0) {
                dfs(grid, i, lastCol);
            }
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            if (grid[i][0] == 0) {
                dfs(grid, i, 0);
            }
        }
        
        for (int i = 0; i < grid[0].size(); ++i) {
            if (grid[lastRow][i] == 0) {
                dfs(grid, lastRow, i);
            }
        }
        
        for (int i = 0; i < grid[0].size(); ++i) {
            if (grid[0][i] == 0) {
                dfs(grid, 0, i);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        visitUnclosedIslands(grid);
        
        int closedIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++closedIslands;
                    dfs(grid, i, j);
                }
            }
        }
        return closedIslands;
    }
};