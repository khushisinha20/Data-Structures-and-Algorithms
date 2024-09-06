//leetcode.com/problems/cut-off-trees-for-golf-event/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<tuple<int, int, int>> getTrees(vector<vector<int>>& forest) {
        vector<tuple<int, int, int>> trees;

        for (int row = 0; row < forest.size(); ++row) {
            for (int col = 0; col < forest[row].size(); ++col) {
                if (forest[row][col] > 1) {
                    trees.push_back({forest[row][col], row, col});
                }
            }
        }

        return trees;
    }

    bool liesInsideGrid(int row, int col, vector<vector<int>>& grid) {
        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
    }

    int minSteps(vector<vector<int>>& forest, int startX, int startY, int targetX, int targetY) {
        int n = forest.size();
        int m = forest[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> cells;
        cells.push({startX, startY});
        visited[startX][startY] = true;
        int steps = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!cells.empty()) {
            int size = cells.size();
            while (size--) {
                auto [currentX, currentY] = cells.front();
                cells.pop();

                if (currentX == targetX && currentY == targetY)
                    return steps;

                for (auto& direction: directions) {
                    int newX = currentX + direction.first;
                    int newY = currentY + direction.second;

                    if (liesInsideGrid(newX, newY, forest) && !visited[newX][newY] && forest[newX][newY] != 0) {
                        cells.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
            ++steps;
        }

        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        vector<tuple<int, int, int>> trees = getTrees(forest);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for (auto& tree: trees)
            minHeap.push(tree);

        int result = 0;
        int startX = 0;
        int startY = 0;

        while (!minHeap.empty()) {
            auto [height, targetX, targetY] = minHeap.top();
            minHeap.pop();

            int currentSteps = minSteps(forest, startX, startY, targetX, targetY);
            if (currentSteps != -1)
                result += currentSteps;
            else
                return -1;

            startX = targetX;
            startY = targetY;
        }

        return result;
    }
};
