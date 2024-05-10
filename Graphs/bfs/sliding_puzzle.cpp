//leetcode.com/problems/sliding-puzzle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toString(vector<vector<int>>& board) {
        string boardToString;

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                boardToString += to_string(board[i][j]);

        return boardToString;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> validMoves = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        string start = toString(board);

        queue<pair<string, int>> boardQueue;
        boardQueue.push({start, 0});
        unordered_set<string> visited;
        visited.insert(start);

        while (!boardQueue.empty()) {
            string currentBoard = boardQueue.front().first;
            int currentMoves = boardQueue.front().second;
            boardQueue.pop();

            if (currentBoard == target)
                return currentMoves;

            int indexOfZero = currentBoard.find('0');
            for (int adjacent : validMoves[indexOfZero]) {
                string nextOrientation = currentBoard;
                swap(nextOrientation[indexOfZero], nextOrientation[adjacent]);
                if (visited.find(nextOrientation) == visited.end()) {
                    visited.insert(nextOrientation);
                    boardQueue.push({nextOrientation, currentMoves + 1});
                }
            }
        }

        return -1;
    }
};
