//leetcode.com/problems/sudoku-solver/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int& row, int& col, char& val) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[row][j] == val)
                return false;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][col] == val)
                return false;
        }
        
        int submatrix_row = (row / 3) * 3;
        int submatrix_col = (col / 3) * 3;
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i + submatrix_row][j + submatrix_col] == val)
                    return false;
            }
        }
        
        return true;
    }
    
    bool solved = false;
    
    void sudokuSolution(vector<vector<char>>& board, int& row, int& col) {
        if (row == board.size()) {
            solved = true;
            return;
        }
        
        int next_row = 0;
        int next_col = 0;
        
        if (col == board[0].size() - 1) {
            next_row = row + 1;
            next_col = 0;
        } else {
            next_row = row;
            next_col = col + 1;
        }
        
        if (board[row][col] != '.') 
            sudokuSolution(board, next_row, next_col);
        else {
            for (char val = '1'; val <= '9'; ++val) {
                if (isValid(board, row, col, val)) {
                    board[row][col] = val;
                    sudokuSolution(board, next_row, next_col);
                    if (solved)
                        return;
                    board[row][col] = '.';
                }
            }
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int row = 0;
        int col = 0;
        sudokuSolution(board, row, col);
    }
};