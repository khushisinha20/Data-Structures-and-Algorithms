//leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool liesInsideMatrix(int row, int col, int m, int n) {
        return row >= 0 and row < m and col >= 0 and col < n;
    }

    int flip(int state, int row, int col, int& m, int& n) {
        vector<pair<int, int>> directions = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto& direction: directions) {
            int newRow = row + direction.first;
            int newCol = col + direction.second;
            if (liesInsideMatrix(newRow, newCol, m, n))
                state ^= (1 << (newRow * n + newCol));
        }

        return state;
    }

    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int start = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1)
                    start |= (1 << (i * n + j));
            }
        }

        if (start == 0)
            return 0;

        queue<pair<int, int>> stateAndStepsQueue;
        unordered_set<int> visited;
        stateAndStepsQueue.push({start, 0});
        visited.insert(start);

        while (!stateAndStepsQueue.empty()) {
            auto [state, steps] = stateAndStepsQueue.front();
            stateAndStepsQueue.pop();

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    int newState = flip(state, i, j, m, n);
                    if (newState == 0)
                        return steps + 1;
                    if (!visited.count(newState)) {
                        visited.insert(newState);
                        stateAndStepsQueue.push({newState, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};
