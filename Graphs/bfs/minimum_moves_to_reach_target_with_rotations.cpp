//leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int horizontal = 0;
        int vertical = 1;

        int n = grid.size();
        queue<tuple<int, int, int, int>> snakes;
        set<tuple<int, int, int>> visited;
        snakes.push({0, 0, horizontal, 0});
        visited.insert({0, 0, horizontal});

        while (!snakes.empty()) {
            auto [row, col, orientation, steps] = snakes.front();
            snakes.pop();

            if (row == n - 1 && col == n - 2 && orientation == horizontal)
                return steps;

            if (orientation == horizontal) {
                if (col + 2 < n && grid[row][col + 2] == 0 && !visited.count({row, col + 1, horizontal})) {
                    snakes.push({row, col + 1, horizontal, steps + 1});
                    visited.insert({row, col + 1, horizontal});
                }

                if (row + 1 < n && grid[row + 1][col] == 0 && grid[row + 1][col + 1] == 0 && !visited.count({row + 1, col, horizontal})) {
                    snakes.push({row + 1, col, horizontal, steps + 1});
                    visited.insert({row + 1, col, horizontal});
                }

                if (row + 1 < n && grid[row + 1][col] == 0 && grid[row + 1][col + 1] == 0 && !visited.count({row, col, vertical})) {
                    snakes.push({row, col, vertical, steps + 1});
                    visited.insert({row, col, vertical});
                }
            }

            if (orientation == vertical) {
                if (row + 2 < n && grid[row + 2][col] == 0 && !visited.count({row + 1, col, vertical})) {
                    snakes.push({row + 1, col, vertical, steps + 1});
                    visited.insert({row + 1, col, vertical}); // Corrected here
                }

                if (col + 1 < n && grid[row][col + 1] == 0 && grid[row + 1][col + 1] == 0 && !visited.count({row, col + 1, vertical})) {
                    snakes.push({row, col + 1, vertical, steps + 1});
                    visited.insert({row, col + 1, vertical});
                }

                if (col + 1 < n && grid[row][col + 1] == 0 && grid[row + 1][col + 1] == 0 && !visited.count({row, col, horizontal})) {
                    snakes.push({row, col, horizontal, steps + 1});
                    visited.insert({row, col, horizontal});
                }
            }
        }

        return -1;
    }
};

