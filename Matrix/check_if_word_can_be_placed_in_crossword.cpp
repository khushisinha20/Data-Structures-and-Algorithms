#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBePlacedHorizontally(vector<vector<char>>& board, string& word, int row, int col) {
        if (col - 1 >= 0 && board[row][col - 1] != '#')
            return false;
        if (col + word.length() < board[0].size() && (board[row][col + word.length()] != '#'))
            return false;
        for (int j = 0; j < word.length(); ++j) {
            if (col + j >= board[0].size())
                return false;
            if (board[row][col + j] == word[j] || board[row][col + j] == ' ') 
                continue;
            else
                return false;
        }
        return true;
    }
    
    bool canBePlacedVertically(vector<vector<char>>& board, string& word, int row, int col) {
        if (row - 1 >= 0 && board[row - 1][col] != '#')
            return false;
        if (row + word.length() < board.size() && board[row + word.length()][col] != '#')
            return false;
        for (int i = 0; i < word.size(); ++i) {
            if (row + i >= board.size())
                return false;
            if (board[row + i][col] == word[i] || board[row + i][col] == ' ')
                continue;
            else
                return false;
        }
        return true;
    }
    
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        string reversed_word = word;
        reverse(reversed_word.begin(), reversed_word.end());
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] || board[i][j] == ' ') {
                    if (canBePlacedHorizontally(board, word, i, j))
                        return true;
                    if (canBePlacedVertically(board, word, i, j))
                        return true;
                }
                if (board[i][j] == reversed_word[0] || board[i][j] == ' ') {
                    if (canBePlacedHorizontally(board, reversed_word, i, j))
                        return true;
                    if (canBePlacedVertically(board, reversed_word, i, j))
                        return true;
                }
            }
        }
        
        return false;
    }
};