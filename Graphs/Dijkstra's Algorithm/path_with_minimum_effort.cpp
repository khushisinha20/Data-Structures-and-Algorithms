//leetcode.com/problems/path-with-minimum-effort/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int row, int col, vector<vector<int>>& heights) {
        return row >= 0 && row < heights.size() && col >= 0 && col < heights[0].size();
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int totalRows = heights.size();
        int totalCols = heights[0].size();
        vector<vector<int>> effort(totalRows, vector<int> (totalCols, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        minHeap.push({0, {0, 0}});
        effort[0][0] = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        while (!minHeap.empty()) {
            auto currentCell = minHeap.top().second;
            int currentHeight = minHeap.top().first;
            minHeap.pop(); 
            
            for (auto direction: directions) {
                int newRow = currentCell.first + direction.first;
                int newCol = currentCell.second + direction.second;
                if (liesInsideGrid(newRow, newCol, heights)) {
                    int currentMinEffort = max(abs(heights[newRow][newCol] - heights[currentCell.first][currentCell.second]), currentHeight);
                    if (currentMinEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = currentMinEffort;
                        minHeap.push({currentMinEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};