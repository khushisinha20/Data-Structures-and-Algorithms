//leetcode.com/problems/valid-sudoku/submissions/

#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), subboxes(9);
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] != '.') {
                    int curr = board[row][col] - '0';
                    if (rows[row].count(curr) || cols[col].count(curr) || subboxes[(row / 3) * 3 + col / 3].count(curr))
                        return false;
                    rows[row].insert(curr);
                    cols[col].insert(curr);
                    subboxes[(row / 3) * 3 + col / 3].insert(curr);
                }
            }
        }
        return true;
    }
};