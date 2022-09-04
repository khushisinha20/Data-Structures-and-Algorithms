//leetcode.com/problems/surrounded-regions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col] || board[row][col] == 'X')
            return;
        
        visited[row][col] = true;
        for (auto direction: directions) {
            int neighbour_row = row + direction.first;
            int neighbour_col = col + direction.second;
            dfs(board, visited, neighbour_row, neighbour_col);
        }
    }
    
    void traverseBorders(vector<vector<char>>& board, vector<vector<bool>>& visited) {
        for (int col = 0; col < board[0].size(); ++col) {
            if (!visited[0][col] && board[0][col] == 'O')
                dfs(board, visited, 0, col);
            if (!visited[board.size() - 1][col] && board[board.size() - 1][col] == 'O')
                dfs(board, visited, board.size() - 1, col);
        }
        
        for (int row = 0; row < board.size(); ++row) {
            if (!visited[row][0] && board[row][0] == 'O')
                dfs(board, visited, row, 0);
            if (!visited[row][board[0].size() - 1] && board[row][board[0].size() - 1] == 'O')
                dfs(board, visited, row, board[0].size() - 1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        traverseBorders(board, visited);
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (!visited[row][col] && board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
            }
        }
    }
};