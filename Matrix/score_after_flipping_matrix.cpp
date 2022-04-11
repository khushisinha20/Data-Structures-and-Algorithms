//leetcode.com/problems/score-after-flipping-matrix/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void flipRow(vector<vector<int> >& grid, int row) {
        for (int i = 0; i < grid[0].size(); ++i) {
            grid[row][i] = 1 - grid[row][i];
        }
    }
    
    void flipCol(vector<vector<int> >& grid, int col) {
        for (int i = 0; i < grid.size(); ++i) {
            grid[i][col] = 1 - grid[i][col];
        }
    }
    
    void makeSetBitOne(vector<vector<int> >& grid) {
        for (int row = 0; row < grid.size(); ++row) {
            if (grid[row][0] == 0) {
                flipRow(grid, row);
            }
        }
    }
    
    void makeElementsOne(vector<vector<int> >& grid) {
        for (int col = 0; col < grid[0].size(); ++col) {
            int ones = 0;
            int zeroes = 0;
            for (int row = 0; row < grid.size(); ++row) {
                if (grid[row][col] == 1)
                    ++ones;
                else
                    ++zeroes;
            }
            if (zeroes > ones) {
                flipCol(grid, col);
            }
        }
    }
    
    int matrixScore(vector<vector<int> >& grid) {
        makeSetBitOne(grid);
        makeElementsOne(grid);
        int score = 0;
        for (int row = 0; row < grid.size(); ++row) {
            int position = 0;
            for (int col = grid[0].size() - 1; col >= 0; --col) {
                score += grid[row][col] * pow(2, position);
                ++position;
            }
        }
        return score;
    }
};