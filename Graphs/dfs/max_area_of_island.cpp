//leetcode.com/problems/max-area-of-island/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int currentIslandArea(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || !grid[row][col])
            return 0;
        
        visited[row][col] = true;
        
        return 1 + currentIslandArea(grid, visited, row + 1, col) + currentIslandArea(grid, visited, row - 1, col) + currentIslandArea(grid, visited, row, col - 1) + currentIslandArea(grid, visited, row, col + 1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        int maxArea = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] && !visited[row][col]) {
                    maxArea = max(maxArea, currentIslandArea(grid, visited, row, col));
                }
            }
        }
        return maxArea;
    }
};