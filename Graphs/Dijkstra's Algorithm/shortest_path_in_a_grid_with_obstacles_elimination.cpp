//leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> shortestDistance(rows, vector<int> (cols, INT_MAX));
        shortestDistance[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({grid[0][0], 0, 0, 0});
        
        while (!minHeap.empty()) {
            int obstaclesVisited = minHeap.top()[0];
            int currentDistance = minHeap.top()[1];
            int currentRow = minHeap.top()[2];
            int currentCol = minHeap.top()[3];
            minHeap.pop();
            
            for (auto& direction: directions) {
                int nextRow = currentRow + direction.first;
                int nextCol = currentCol + direction.second;
                
                if (nextRow >= 0 and nextRow < rows and nextCol >= 0 and nextCol < cols and currentDistance + 1 < shortestDistance[nextRow][nextCol] and obstaclesVisited + grid[nextRow][nextCol] <= k) {
                    shortestDistance[nextRow][nextCol] = currentDistance + 1;
                    minHeap.push({obstaclesVisited + grid[nextRow][nextCol], currentDistance + 1, nextRow, nextCol});
                }
            }
        }
        
        return shortestDistance[rows - 1][cols - 1] == INT_MAX ? -1 : shortestDistance[rows - 1][cols - 1];
    }
};