//leetcode.com/problems/cat-and-mouse-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[9][9][9][9][101];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool isWithinBounds(int row, int col, int rows, int cols) {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    bool helper(vector<string>& grid, int& catJump, int& mouseJump, int catRow, int catCol, int mouseRow, int mouseCol, int moves) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (moves >= 100)
            return false;

        if (mouseRow == catRow && mouseCol == catCol)
            return false;

        if (grid[catRow][catCol] == 'F')
            return false;

        if (grid[mouseRow][mouseCol] == 'F')
            return true;

        if (dp[catRow][catCol][mouseRow][mouseCol][moves] != -1)
            return dp[catRow][catCol][mouseRow][mouseCol][moves];

        if (moves % 2 == 0) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= mouseJump; ++j) {
                    int nextRow = mouseRow + j * dx[i];
                    int nextCol = mouseCol + j * dy[i];
                    if (isWithinBounds(nextRow, nextCol, rows, cols) && grid[nextRow][nextCol] != '#') {
                        if (helper(grid, catJump, mouseJump, catRow, catCol, nextRow, nextCol, moves + 1)) {
                            return dp[catRow][catCol][mouseRow][mouseCol][moves] = true;
                        }
                    } else {
                        break;
                    }
                }
            }
            return dp[catRow][catCol][mouseRow][mouseCol][moves] = false;
        } else {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j <= catJump; ++j) {
                    int nextRow = catRow + j * dx[i];
                    int nextCol = catCol + j * dy[i];
                    if (isWithinBounds(nextRow, nextCol, rows, cols) && grid[nextRow][nextCol] != '#') {
                        if (!helper(grid, catJump, mouseJump, nextRow, nextCol, mouseRow, mouseCol, moves + 1)) {
                            return dp[catRow][catCol][mouseRow][mouseCol][moves] = false;
                        }
                    } else {
                        break;
                    }
                }
            }
            return dp[catRow][catCol][mouseRow][mouseCol][moves] = true;
        }
    }

    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        memset(dp, -1, sizeof dp);
        int rows = grid.size();
        int cols = grid[0].size();
        int catRow, catCol, mouseRow, mouseCol;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 'C') {
                    catRow = i;
                    catCol = j;
                } else if (grid[i][j] == 'M') {
                    mouseRow = i;
                    mouseCol = j;
                }
            }
        }

        return helper(grid, catJump, mouseJump, catRow, catCol, mouseRow, mouseCol, 0);
    }
};
