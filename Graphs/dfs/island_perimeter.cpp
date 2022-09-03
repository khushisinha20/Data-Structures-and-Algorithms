//leetcode.com/problems/island-perimeter/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int& perimeter) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col]) {
            ++perimeter;
            return;
        }
        
        if (grid[row][col] == 2)
            return;
        
        grid[row][col] = 2;
        
        dfs(grid, row + 1, col, perimeter);
        dfs(grid, row - 1, col, perimeter);
        dfs(grid, row, col + 1, perimeter);
        dfs(grid, row, col - 1, perimeter);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int row = 0; row < grid.size(); ++row) {
           for (int col = 0; col < grid[0].size(); ++col) {
               if (grid[row][col] == 1)
                   dfs(grid, row, col, perimeter);
           }
        }
        return perimeter;
    }
};