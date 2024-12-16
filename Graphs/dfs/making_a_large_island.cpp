//leetcode.com/problems/making-a-large-island/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, int regionId, vector<vector<int>>& directions) {
        int n = grid.size();
        if (row < 0 or row >= n or col < 0 or col >= n or grid[row][col] != 1)
            return 0;

        grid[row][col] = regionId;
        int size = 1;
        for (auto& direction: directions) {
            size += dfs(grid, row + direction[0], col + direction[1], regionId, directions);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, int> regionToArea;
        int regionId = 2;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j, regionId, directions);
                    regionToArea[regionId++] = area;
                }
            }
        }

        int maxIsland = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueRegions;
                    int newSize = 1;

                    for (auto& direction: directions) {
                        int newRow = i + direction[0];
                        int newCol = j + direction[1];
                        if (newRow >= 0 and newCol >= 0 and newRow < n and newCol < n) {
                            int neighborRegion = grid[newRow][newCol];
                            if (neighborRegion > 1 and uniqueRegions.find(neighborRegion) == uniqueRegions.end()) {
                                newSize += regionToArea[neighborRegion];
                                uniqueRegions.insert(neighborRegion);
                            }
                        }
                    }

                    maxIsland = max(maxIsland, newSize);
                }
            }
        }

        if (maxIsland == 0) {
            for (const auto& entry : regionToArea) {
                maxIsland = max(maxIsland, entry.second);
            }
        }

        return maxIsland;
    }
};
