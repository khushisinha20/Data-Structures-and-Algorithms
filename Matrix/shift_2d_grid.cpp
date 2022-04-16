//leetcode.com/problems/shift-2d-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int to_linear_array_index(vector<vector<int>>& grid, int k, int current_row, int current_col) {
        return (current_row * grid[0].size() + current_col + k) % (grid.size() * grid[0].size());
    }
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> shifted_grid(grid.size(), vector<int> (grid[0].size(), 0));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                int shifted_row = (to_linear_array_index(grid, k, i, j)) / grid[0].size();
                int shifted_col = (to_linear_array_index(grid, k, i, j)) % grid[0].size();
                shifted_grid[shifted_row][shifted_col] = grid[i][j];
            }
        }
        return shifted_grid;
    }
};