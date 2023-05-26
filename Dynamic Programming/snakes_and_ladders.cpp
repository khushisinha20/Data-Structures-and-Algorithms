//leetcode.com/problems/snakes-and-ladders/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> moveTracker;
        int n = board.size();
        vector<bool> visited((n * n) + 1, false);

        moveTracker.push({1, 0});
        visited[1] = true;

        int row, col, cell;

        while (!moveTracker.empty()) {
            auto [currentCell, moves] = moveTracker.front();
            moveTracker.pop();

                for (int dice = 1; dice <= 6; ++dice) {
                    cell = currentCell + dice;
                    if (cell % n == 0) {
                        row = n - (cell / n);
                        col = (cell / n) & 1 ? n - 1 : 0;
                    } else {
                        row = n - (cell / n) - 1;
                        col = (cell / n) & 1 ? n - (cell % n) : (cell % n) - 1;
                    }


                if (board[row][col] != -1)
                    cell = board[row][col];

                if (cell == n * n)
                    return moves + 1;

                if (!visited[cell]) {
                    moveTracker.push({cell, moves + 1});
                    visited[cell] = true;
                }
            }
        }

        return -1;
    }
};
