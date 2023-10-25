//leetcode.com/problems/trapping-rain-water-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (row == 0 or row == rows - 1 or col == 0 or col == cols - 1) {
                    visited[row][col] = true;
                    minHeap.push({heightMap[row][col], row, col});
                }
            }
        }
        
        int trappedWater = 0;
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!minHeap.empty()) {
            auto currentCell = minHeap.top();
            int height = currentCell[0];
            int row = currentCell[1];
            int col = currentCell[2];
            minHeap.pop();
            
            for (auto& direction: directions) {
                int newRow = row + direction[0];
                int newCol = col + direction[1];
                
                if (newRow >= 0 and newRow < rows and newCol >= 0 and newCol < cols and !visited[newRow][newCol]) {
                    trappedWater += max(0, height - heightMap[newRow][newCol]);
                    minHeap.push({max(height, heightMap[newRow][newCol]), newRow, newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }
        
        return trappedWater;
    }
};