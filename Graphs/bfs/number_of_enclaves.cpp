//leetcode.com/problems/number-of-enclaves/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool liesOnBorder(vector<vector<int>>& grid, int& row, int& col) {
        return row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1;
    }
    
    bool liesInsideGrid(vector<vector<int>>& grid, int& row, int& col) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& coordinates) {
        while (!coordinates.empty()) {
            int current_row = coordinates.front().first;
            int current_col = coordinates.front().second;
            coordinates.pop();
            for (auto direction: directions) {
                int neighbour_row = current_row + direction.first;
                int neighbour_col = current_col + direction.second;
                if (liesInsideGrid(grid, neighbour_row, neighbour_col) && !visited[neighbour_row][neighbour_col] && grid[neighbour_row][neighbour_col] == 1) {
                    visited[neighbour_row][neighbour_col] = true;
                    coordinates.push({neighbour_row, neighbour_col});
                }
            }
        }
    }
    
    void storeBorderLandCells(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& coordinates) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (liesOnBorder(grid, row, col)) {
                    if (grid[row][col] == 1) {
                        visited[row][col] = true;
                        coordinates.push({row, col});
                    }
                }
            }
        }
    }
    
    int unvisitedLandCells(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int unvisited_land_cells = 0;
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[0].size(); ++col)
                if (grid[row][col] == 1 && !visited[row][col])
                    ++unvisited_land_cells;
        return unvisited_land_cells;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        queue<pair<int, int>> coordinates;
        storeBorderLandCells(grid, visited, coordinates);
        bfs(grid, visited, coordinates);
        return unvisitedLandCells(grid, visited);
    }
};