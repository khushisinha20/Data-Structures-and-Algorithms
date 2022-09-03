//leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool liesInsideGrid(int& row, int& col, vector<vector<char>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int& row, int& col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            for (auto direction: directions) {
                int neighbour_row = direction.first + row;
                int neighbour_col = direction.second + col;
                if (liesInsideGrid(neighbour_row, neighbour_col, grid) && !visited[neighbour_row][neighbour_col] && grid[row][col] == '1') {
                    visited[neighbour_row][neighbour_col] = true;
                    q.push({neighbour_row, neighbour_col});
                }
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int total_rows = grid.size();
        int total_cols = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(total_rows, vector<bool> (total_cols, false));
        for (int row = 0; row < total_rows; ++row) {
            for (int col = 0; col < total_cols; ++col) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    ++islands;
                    bfs(grid, visited, row, col);
                }
            }
        }
        return islands;
    }
};