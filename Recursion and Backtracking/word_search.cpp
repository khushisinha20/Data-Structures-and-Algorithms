//leetcode.com/problems/word-search/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int currentIndex) {
        if (currentIndex == word.length())
            return true;
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[currentIndex])
            return false;
        
        bool foundElement = false;
        board[row][col] = '.';
        for (auto direction: directions) {
            foundElement |= dfs(board, word, row + direction.first, col + direction.second, currentIndex + 1);
        }
        board[row][col] = word[currentIndex];
        
        return foundElement;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == word[0] && dfs(board, word, row, col, 0))
                    return true;
            }
        }
        return false;
    }
};