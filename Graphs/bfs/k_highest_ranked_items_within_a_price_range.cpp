//leetcode.com/problems/k-highest-ranked-items-within-a-price-range/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideGrid(int currentRow, int currentCol, int n, int m) {
        return currentRow >= 0 && currentRow < n && currentCol >= 0 && currentCol < m;
    }

    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<tuple<int, int, int, int>> maxHeap;

        int startRow = start[0];
        int startCol = start[1];
        queue<pair<int, int>> bfsQueue;
        visited[startRow][startCol] = true;
        bfsQueue.push({startRow, startCol});
        int low = pricing[0];
        int high = pricing[1];

        int distance = 0;
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            while (size--) {
                int row = bfsQueue.front().first;
                int col = bfsQueue.front().second;
                bfsQueue.pop();

                if (grid[row][col] != 0) {
                    if (grid[row][col] != 1 && grid[row][col] >= low && grid[row][col] <= high) {
                        maxHeap.push({distance, grid[row][col], row, col});
                        if (maxHeap.size() > k)
                            maxHeap.pop();
                    }

                    for (auto& direction : directions) {
                        int newRow = row + direction[0];
                        int newCol = col + direction[1];
                        if (liesInsideGrid(newRow, newCol, n, m) && !visited[newRow][newCol]) {
                            bfsQueue.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            ++distance;
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int row = get<2>(maxHeap.top());
            int col = get<3>(maxHeap.top());
            maxHeap.pop();
            result.push_back({row, col});
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
