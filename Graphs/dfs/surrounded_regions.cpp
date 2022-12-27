//leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool liesInsideBoard(vector<vector<char>>& board, int row, int col) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        visited[row][col] = true;
        
        for (auto direction: directions) {
            int adjacentRow = row + direction[0];
            int adjacentCol = col + direction[1];
            if (liesInsideBoard(board, adjacentRow, adjacentCol) && !visited[adjacentRow][adjacentCol] && board[adjacentRow][adjacentCol] == 'O') 
                dfs(board, visited, adjacentRow, adjacentCol);
        }
    }
    
    void traverseBorder(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)
                    if (board[i][j] == 'O')
                        dfs(board, visited, i, j);
            }
        }
    }
    
    void updateBoard(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int i = 1; i < board.size() - 1; ++i) {
            for (int j = 1; j < board[i].size() - 1; ++j) {
                if (board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        traverseBorder(board, visited);
        updateBoard(board, visited);
    }
};