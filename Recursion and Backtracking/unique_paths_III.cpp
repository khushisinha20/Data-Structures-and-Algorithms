//leetcode.com/problems/unique-paths-iii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int number_of_walks(vector<vector<int>>& grid, int row, int col, int total_cells_possible, int total_cells_walked, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return 0;
        
        if (grid[row][col] == -1 || visited[row][col])
            return 0;
        
        if ((grid[row][col] == 2) && (total_cells_possible != total_cells_walked))
            return 0;
        
        if ((grid[row][col] == 2) && (total_cells_possible == total_cells_walked))
            return 1;
        
        visited[row][col] = true;
        int up = number_of_walks(grid, row - 1, col, total_cells_possible, total_cells_walked + 1, visited);
        int down = number_of_walks(grid, row + 1, col, total_cells_possible, total_cells_walked + 1, visited);
        int left = number_of_walks(grid, row, col - 1, total_cells_possible, total_cells_walked + 1, visited);
        int right = number_of_walks(grid, row, col + 1, total_cells_possible, total_cells_walked + 1, visited);
        visited[row][col] = false;
        
        int ans = up + down + left + right;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        int obstacles = 0;
        int total_cells_possible = grid.size() * grid[0].size();
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
                if (grid[i][j] == -1)
                    ++obstacles;
            }
        }
        total_cells_possible = total_cells_possible - obstacles - 1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        return number_of_walks(grid, row, col, total_cells_possible, 0, visited);
    }
};