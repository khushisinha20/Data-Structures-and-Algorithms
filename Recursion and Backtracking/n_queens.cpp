//leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isQueenSafe(vector<string>& board, int row, int col, int n) {
        for (int i = row - 1, j = col; i >= 0; --i) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void arrangeQueens(vector<vector<string>>& res, vector<string>& board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            if (isQueenSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                arrangeQueens(res, board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        arrangeQueens(res, board, 0, n);
        return res;
    }
};