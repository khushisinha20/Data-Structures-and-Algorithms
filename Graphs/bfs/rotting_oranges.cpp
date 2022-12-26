//leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    } 
    
    bool isUnvisitedFreshNeighbourOrange(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        return liesInsideGrid(row, col, grid) && grid[row][col] == 1 && !visited[row][col];
    }
    
    void fillInitiallyRottenOranges(queue<pair<pair<int, int>, int>>& oranges, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (grid[row][col] == 2) {
                    oranges.push({{row, col}, 0});
                    visited[row][col] = true;
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& grid, int& totalTime, vector<vector<bool>>& visited) {
        queue<pair<pair<int, int>, int>> oranges;
        fillInitiallyRottenOranges(oranges, grid, visited);
        
        while (!oranges.empty()) {
            pair<int, int> currentOrange = oranges.front().first;
            int currentTime = oranges.front().second;
            int currentRow = currentOrange.first;
            int currentCol = currentOrange.second;
            oranges.pop();
            
            if (isUnvisitedFreshNeighbourOrange(currentRow - 1, currentCol, grid, visited)) {
                oranges.push({{currentRow - 1, currentCol}, currentTime + 1});
                visited[currentRow - 1][currentCol] = true;   
            }
            
            if (isUnvisitedFreshNeighbourOrange(currentRow + 1, currentCol, grid, visited)) {
                oranges.push({{currentRow + 1, currentCol}, currentTime + 1});
                visited[currentRow + 1][currentCol] = true;
            }
            
            if (isUnvisitedFreshNeighbourOrange(currentRow, currentCol - 1, grid, visited)) {
                oranges.push({{currentRow, currentCol - 1}, currentTime + 1});
                visited[currentRow][currentCol - 1] = true;   
            }
            
            if (isUnvisitedFreshNeighbourOrange(currentRow, currentCol + 1, grid, visited)) {
                oranges.push({{currentRow, currentCol + 1}, currentTime + 1});
                visited[currentRow][currentCol + 1] = true;   
            }
            
            totalTime = currentTime;
        }
    }
    
    bool hasNoFreshOrange(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (!visited[row][col] && grid[row][col] == 1)
                    return false;
            }
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int totalTime = 0;
        bfs(grid, totalTime, visited);
        return hasNoFreshOrange(grid, visited) ? totalTime: -1;
    }
};