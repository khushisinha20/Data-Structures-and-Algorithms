//leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> findPosition(vector<vector<char>>& grid, char cell) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == cell)
                    return make_pair(i, j);
            }
        }
        return {-1, -1};
    }

    bool isWithinBounds(int row, int col, int m, int n, vector<vector<char>>& grid) {
        return row >= 0 && row < m && col >= 0 && col < n && grid[row][col] != '#';
    }

    bool canReach(int targetRow, int targetCol, int playerRow, int playerCol, vector<vector<char>>& grid, pair<int, int> boxPosition) {
        queue<pair<int, int>> playerCoordinates;
        playerCoordinates.push({playerRow, playerCol});
        set<pair<int, int>> visited;
        visited.insert({playerRow, playerCol});
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!playerCoordinates.empty()) {
            auto [currentRow, currentCol] = playerCoordinates.front();
            playerCoordinates.pop();

            if (currentRow == targetRow && currentCol == targetCol)
                return true;

            for (auto& direction: directions) {
                int newRow = currentRow + direction.first;
                int newCol = currentCol + direction.second;

                if (isWithinBounds(newRow, newCol, m, n, grid) && visited.find({newRow, newCol}) == visited.end() && !(newRow == boxPosition.first && newCol == boxPosition.second)) {
                    visited.insert({newRow, newCol});
                    playerCoordinates.push({newRow, newCol});
                }
            }
        }
        return false;
    }

    int minPushBox(vector<vector<char>>& grid) {
        pair<int, int> player = findPosition(grid, 'S');
        pair<int, int> box = findPosition(grid, 'B');
        pair<int, int> target = findPosition(grid, 'T');

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        queue<tuple<pair<int, int>, pair<int, int>, int>> states;
        states.push({player, box, 0});

        set<pair<pair<int, int>, pair<int, int>>> visited;
        visited.insert({player, box});

        while (!states.empty()) {
            auto [playerPosition, boxPosition, pushes] = states.front();
            states.pop();
            int playerRow = playerPosition.first;
            int playerCol = playerPosition.second;
            int boxRow = boxPosition.first;
            int boxCol = boxPosition.second;

            if (boxPosition == target)
                return pushes;

            for (auto& direction: directions) {
                int newBoxRow = boxRow + direction.first;
                int newBoxCol = boxCol + direction.second;
                int requiredPlayerRow = boxRow - direction.first;
                int requiredPlayerCol = boxCol - direction.second;

                if (isWithinBounds(newBoxRow, newBoxCol, grid.size(), grid[0].size(), grid) && isWithinBounds(requiredPlayerRow, requiredPlayerCol, grid.size(), grid[0].size(), grid) && canReach(requiredPlayerRow, requiredPlayerCol, playerRow, playerCol, grid, boxPosition)) {

                    auto newState = make_pair(make_pair(newBoxRow, newBoxCol), make_pair(boxRow, boxCol));

                    if (visited.find(newState) == visited.end()) {
                        visited.insert(newState);
                        states.push({{requiredPlayerRow, requiredPlayerCol}, {newBoxRow, newBoxCol}, pushes + 1});
                    }
                }
            }
        }

        return -1;
    }
};


