//leetcode.com/problems/game-of-life/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int live_neighbors(int i, int j, vector<vector<int>>& current_state) {
        int liveNeighbors = 0;
        if (i > 0) {
            if (current_state[i - 1][j] == 1 || current_state[i - 1][j] == 2)
                ++liveNeighbors;
        }
        if (i < current_state.size() - 1) {
            if (current_state[i + 1][j] == 1 || current_state[i + 1][j] == 2)
                ++liveNeighbors;
        }
        if (j > 0) {
            if (current_state[i][j - 1] == 1 || current_state[i][j - 1] == 2)
                ++liveNeighbors;
        }
        if (j < current_state[0].size() - 1) {
            if (current_state[i][j + 1] == 1 || current_state[i][j + 1] == 2)
                ++liveNeighbors;
        }
        if (i > 0 && j > 0) {
            if (current_state[i - 1][j - 1] == 1 || current_state[i - 1][j - 1] == 2)
                ++liveNeighbors;
        }
        if (i < current_state.size() - 1 && j < current_state[0].size() - 1) {
            if (current_state[i + 1][j + 1] == 1 || current_state[i + 1][j + 1] == 2)
                ++liveNeighbors;
        }
        if (i > 0 && j < current_state[0].size() - 1) {
            if (current_state[i - 1][j + 1] == 1 || current_state[i - 1][j + 1] == 2)
                ++liveNeighbors;
        }
        if (i < current_state.size() - 1 && j > 0) {
            if (current_state[i + 1][j - 1] == 1 || current_state[i + 1][j - 1] == 2)
                ++liveNeighbors;
        }
        return liveNeighbors;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int previously_live = 2;
        int previously_dead = 3;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 1) {
                    if (live_neighbors(i, j, board) < 2 || live_neighbors(i, j, board) > 3)
                        board[i][j] = previously_live;
                } else if (board[i][j] == 0) {
                    if (live_neighbors(i, j, board) == 3)
                        board[i][j] = previously_dead;
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == previously_live)
                    board[i][j] = 0;
                else if (board[i][j] == 1 || board[i][j] == previously_dead)
                    board[i][j] = 1;
            }
        }
    }
};