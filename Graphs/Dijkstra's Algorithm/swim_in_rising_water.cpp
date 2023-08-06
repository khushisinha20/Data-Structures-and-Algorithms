//leetcode.com/problems/swim-in-rising-water/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> time(rows, vector<int>(cols, INT_MAX));
        time[0][0] = grid[0][0]; 
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({grid[0][0], {0, 0}});
        
        while (!minHeap.empty()) {
            int currentTime = minHeap.top().first;
            int currentRow = minHeap.top().second.first;
            int currentCol = minHeap.top().second.second;
            
            minHeap.pop();
            
            if (currentRow == rows - 1 && currentCol == cols - 1) 
                return currentTime;
            
            for (auto& direction : directions) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];
                
                if (liesInsideGrid(newRow, newCol, grid)) {
                    int reachingTime = max(currentTime, grid[newRow][newCol]); 
                    if (time[newRow][newCol] > reachingTime) {
                        time[newRow][newCol] = reachingTime;
                        minHeap.push({reachingTime, {newRow, newCol}});
                    }
                }
            }
        }
        
        return -1;
    }
};