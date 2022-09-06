//practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool liesInsideGrid(vector<vector<int>>& grid, int& row, int& col) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
  
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int current_row, int current_col, int base_row, int base_col, vector<pair<int, int>>& island) {
        if (!liesInsideGrid(grid, current_row, current_col) || visited[current_row][current_col] || grid[current_row][current_col] == 0)
            return;
            
        island.push_back({current_row - base_row, current_col - base_col});
        visited[current_row][current_col] = true;
        
        dfs(grid, visited, current_row + 1, current_col, base_row, base_col, island);
        dfs(grid, visited, current_row - 1, current_col, base_row, base_col, island);
        dfs(grid, visited, current_row, current_col + 1, base_row, base_col, island);
        dfs(grid, visited, current_row, current_col - 1, base_row, base_col, island);
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        set<vector<pair<int, int>>> distinct_islands;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (!visited[row][col] && grid[row][col] == 1) {
                    vector<pair<int, int>> island;
                    dfs(grid, visited, row, col, row, col, island);
                    distinct_islands.insert(island);
                }
            }
        }
        return distinct_islands.size();
    }
};