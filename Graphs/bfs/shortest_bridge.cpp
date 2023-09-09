//leetcode.com/problems/shortest-bridge/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidCell(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }
    
    void dfsMarkIsland(vector<vector<int>>& grid, queue<pair<int, int>>& bfsQueue, int row, int col, set<pair<int, int>>& visitedCells) {
        if (!isValidCell(grid, row, col) || visitedCells.count({row, col}) || grid[row][col] == 0)
            return;
        
        visitedCells.insert({row, col});
        bfsQueue.push({row, col});
        
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (const auto& direction : directions) {
            int newRow = row + direction.first;
            int newCol = col + direction.second;
            
            dfsMarkIsland(grid, bfsQueue, newRow, newCol, visitedCells);
        }
    }
    
    int bfsFindBridge(vector<vector<int>>& grid, set<pair<int, int>>& visitedCells, queue<pair<int, int>>& bfsQueue) {
        static const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int level = 0;
        
        while (!bfsQueue.empty()) {
            int nodesAtCurrentLevel = bfsQueue.size();
            
            while (nodesAtCurrentLevel--) {
                auto currentCell = bfsQueue.front();
                bfsQueue.pop();
                
                for (const auto& direction : directions) {
                    int newRow = currentCell.first + direction.first;
                    int newCol = currentCell.second + direction.second;
                    
                    if (isValidCell(grid, newRow, newCol) && !visitedCells.count({newRow, newCol})) {
                        if (grid[newRow][newCol] == 1)
                            return level;
                        
                        visitedCells.insert({newRow, newCol});
                        bfsQueue.push({newRow, newCol});
                    }
                }
            }
            ++level;
        }
        
        return level;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        set<pair<int, int>> visitedCells;
        queue<pair<int, int>> bfsQueue;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 1) {
                    dfsMarkIsland(grid, bfsQueue, i, j, visitedCells);
                    return bfsFindBridge(grid, visitedCells, bfsQueue);
                }
            }
        }
        
        return -1;
    }
};
