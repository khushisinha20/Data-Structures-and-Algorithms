//leetcode.com/problems/shortest-path-in-binary-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size(); 
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         if (grid[0][0] == 1)
            return -1;
        
        if (grid[0].size() == 1 && grid[0][0] == 0)
            return 1;
        
        
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        vector<vector<int>> distance(totalRows, vector<int> (totalCols, INT_MAX));
        queue<pair<int, pair<int, int>>> nodes;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        
        distance[0][0] = 1;
        nodes.push({1, {0, 0}});
        
        while (!nodes.empty()) {
            auto currentCell = nodes.front().second;
            int currentDistance = nodes.front().first;
            nodes.pop();
            for (auto direction: directions) {
                int newRow = currentCell.first + direction.first;
                int newCol = currentCell.second + direction.second;
                if (liesInsideGrid(newRow, newCol, grid) && grid[newRow][newCol] == 0 && currentDistance + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = currentDistance + 1;
                    if (newRow == totalRows - 1 && newCol == totalCols - 1)
                        return distance[newRow][newCol];
                    nodes.push({distance[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};