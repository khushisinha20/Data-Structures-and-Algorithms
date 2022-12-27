//leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTraversableNeighbour(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && !visited[row][col];
    }
    
    void storeZeroes(queue<pair<pair<int, int>, int>>& cells, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
        for (int row = 0; row < mat.size(); ++row) {
            for (int col = 0; col < mat[row].size(); ++col) {
                if (!mat[row][col]) {
                    cells.push({{row, col}, 0});
                    visited[row][col] = true;   
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& nearest0Distance) {
        queue<pair<pair<int, int>, int>> cells;
        vector<vector<bool>> visited(mat.size(), vector<bool> (mat[0].size(), false));
        storeZeroes(cells, mat, visited);
        
        while (!cells.empty()) {
            int currentRow = cells.front().first.first;
            int currentCol = cells.front().first.second;
            int currentTime = cells.front().second;
            cells.pop();
            
            if (mat[currentRow][currentCol] == 1)
                nearest0Distance[currentRow][currentCol] = currentTime;
            
            if (isTraversableNeighbour(mat, currentRow - 1, currentCol, visited)) {
                cells.push({{currentRow - 1, currentCol}, currentTime + 1});
                visited[currentRow - 1][currentCol] = true;
            }
            
            if (isTraversableNeighbour(mat, currentRow + 1, currentCol, visited)) {
                cells.push({{currentRow + 1, currentCol}, currentTime + 1});
                visited[currentRow + 1][currentCol] = true;
            }
            
            if (isTraversableNeighbour(mat, currentRow, currentCol - 1, visited)) {
                cells.push({{currentRow, currentCol - 1}, currentTime + 1});
                visited[currentRow][currentCol - 1] = true;
            }
            
            if (isTraversableNeighbour(mat, currentRow, currentCol + 1, visited)) {
                cells.push({{currentRow, currentCol + 1}, currentTime + 1});
                visited[currentRow][currentCol + 1] = true;
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> nearest0Distance(mat.size(), vector<int> (mat[0].size(), 0));
        bfs(mat, nearest0Distance);
        return nearest0Distance;
    }
};