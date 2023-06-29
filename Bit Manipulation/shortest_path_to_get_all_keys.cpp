//leetcode.com/problems/shortest-path-to-get-all-keys/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isLock(char c) {
        return c >= 'A' and c <= 'Z';
    }

    bool isKey(char c) {
        return c >= 'a' and c <= 'z';
    }

    bool liesInsideGrid(int row, int col, vector<string>& grid) {
        return row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size();
    }

    pair<int, int> getStartingPosition(vector<string>& grid) {
        for (int row = 0; row < grid.size(); ++row)
            for (int col = 0; col < grid[row].size(); ++col)
                if (grid[row][col] == '@')
                    return {row, col};
        return {-1, -1};
    }

    int getTotalKeys(vector<string>& grid) {
        int totalKeys = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[row].size(); ++col) {
                if (isKey(grid[row][col]))
                    ++totalKeys;
            }
        }
        return totalKeys;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();
        int totalKeys = getTotalKeys(grid);
        int totalKeysMask = pow(2, totalKeys) - 1;
        bool visited[totalRows][totalCols][totalKeysMask + 1];
        memset(visited, false, sizeof visited);
        auto startingCoordinates = getStartingPosition(grid);
        int startingRow = startingCoordinates.first;
        int startingCol = startingCoordinates.second;
        queue<vector<int>> positions;
        positions.push({startingRow, startingCol, 0, 0});
        visited[startingRow][startingCol][0] = true;

        int currentKeyMask = 0;
        
        while (!positions.empty()) {
            int row = positions.front()[0];
            int col = positions.front()[1];
            int moves = positions.front()[2];
            currentKeyMask = positions.front()[3];
            positions.pop();
            
            if (currentKeyMask == totalKeysMask)
                return moves;
            
            for (auto& direction: directions) {
                int newRow = direction[0] + row;
                int newCol = direction[1] + col;
                if (liesInsideGrid(newRow, newCol, grid) and grid[newRow][newCol] != '#') {
                    if (isKey(grid[newRow][newCol])) {
                        int newMask = currentKeyMask | (1 << (grid[newRow][newCol] - 'a'));
                        if (!visited[newRow][newCol][newMask]) {
                            visited[newRow][newCol][newMask] = true;
                            positions.push({newRow, newCol, moves + 1, newMask});
                        }
                    } else if (isLock(grid[newRow][newCol])) {
                        if (!visited[newRow][newCol][currentKeyMask] and ((currentKeyMask >> (grid[newRow][newCol] - 'A')) & 1) == 1) {
                            visited[newRow][newCol][currentKeyMask] = true;
                            positions.push({newRow, newCol, moves + 1, currentKeyMask});
                        }
                    } else {
                        if (!visited[newRow][newCol][currentKeyMask]) {
                            visited[newRow][newCol][currentKeyMask] = true;
                            positions.push({newRow, newCol, moves + 1, currentKeyMask});
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};
