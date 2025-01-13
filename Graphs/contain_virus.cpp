//leetcode.com/problems/contain-virus/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size();
        int n = isInfected[0].size();
        int totalWalls = 0;

        while (true) {
            vector<vector<int>> regions;
            vector<unordered_set<int>> threats;
            vector<int> wallsNeeded;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        processRegion(isInfected, i, j, visited, regions, threats, wallsNeeded, directions, m, n);
                    }
                }
            }

            if (regions.empty()) 
                break;

            int maxThreatIndex = getMaxThreatIndex(threats);
            if (maxThreatIndex == -1) 
                break;

            totalWalls += wallsNeeded[maxThreatIndex];
            quarantineRegion(isInfected, regions[maxThreatIndex], n);
            spreadVirus(isInfected, regions, threats, maxThreatIndex, n);
        }

        return totalWalls;
    }

private:
    void processRegion(vector<vector<int>>& isInfected, int i, int j, vector<vector<bool>>& visited,
                       vector<vector<int>>& regions, vector<unordered_set<int>>& threats,
                       vector<int>& wallsNeeded, vector<pair<int, int>>& directions, int m, int n) {
        queue<pair<int, int>> cells;
        cells.push({i, j});
        visited[i][j] = true;

        vector<int> region;
        unordered_set<int> threat;
        int walls = 0;

        while (!cells.empty()) {
            auto [currentRow, currentCol] = cells.front();
            cells.pop();
            region.push_back(currentRow * n + currentCol);

            for (auto& [directionX, directionY] : directions) {
                int newRow = currentRow + directionX;
                int newCol = currentCol + directionY;
                if (isWithinBounds(newRow, newCol, m, n)) {
                    if (isInfected[newRow][newCol] == 0) {
                        threat.insert(newRow * n + newCol);
                        ++walls;
                    } else if (isInfected[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                        cells.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
        }

        regions.push_back(region);
        threats.push_back(threat);
        wallsNeeded.push_back(walls);
    }

    int getMaxThreatIndex(const vector<unordered_set<int>>& threats) {
        int maxThreatIndex = -1;
        int maxThreatSize = 0;
        for (int i = 0; i < threats.size(); ++i) {
            if (threats[i].size() > maxThreatSize) {
                maxThreatSize = threats[i].size();
                maxThreatIndex = i;
            }
        }
        return maxThreatIndex;
    }

    void quarantineRegion(vector<vector<int>>& isInfected, const vector<int>& region, int n) {
        for (int cell : region) {
            isInfected[cell / n][cell % n] = -1;
        }
    }

    void spreadVirus(vector<vector<int>>& isInfected, const vector<vector<int>>& regions,
                     const vector<unordered_set<int>>& threats, int maxThreatIndex, int n) {
        for (int i = 0; i < regions.size(); ++i) {
            if (i == maxThreatIndex) continue;
            for (int cell : threats[i]) {
                int x = cell / n;
                int y = cell % n;
                isInfected[x][y] = 1;
            }
        }
    }

    bool isWithinBounds(int row, int col, int m, int n) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};

