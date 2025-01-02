//leetcode.com/problems/zuma-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeGroups(string board) {
        bool found = true;
        while (found) {
            found = false;
            int n = board.length();
            int start = 0;
            for (int i = 0; i <= n; ++i) {
                if (i == n || board[i] != board[start]) {
                    if (i - start >= 3) {
                        board = board.substr(0, start) + board.substr(i);
                        found = true;
                        break;
                    }
                    start = i;
                }
            }
        }
        return board;
    }

    string serializeCount(const vector<int>& count) {
        string serialized = "";
        for (int c : count) {
            serialized += to_string(c) + "#";
        }
        return serialized;
    }

    int dfs(string board, vector<int>& count, unordered_map<string, int>& memo) {
        if (board.empty())
            return 0;

        string key = board + serializeCount(count);

        if (memo.count(key))
            return memo[key];

        int result = INT_MAX;
        int n = board.size();

        for (int i = 0; i <= n; ++i) {
            for (char c : {'R', 'Y', 'B', 'G', 'W'}) {
                if (count[c - 'A'] == 0)
                    continue;

                bool worthTrying = false;
                if (board[i] == c)
                    worthTrying = true;
                else if (i > 0 and board[i] == board[i - 1] and board[i] != c)
                    worthTrying = true;

                if (worthTrying and count[c - 'A'] > 0) {
                    --count[c - 'A'];
                    string newBoard = board.substr(0, i) + c + board.substr(i);
                    newBoard = removeGroups(newBoard);

                    int nextStep = dfs(newBoard, count, memo);
                    if (nextStep != INT_MAX)
                        result = min(result, 1 + nextStep);

                    ++count[c - 'A'];
                }
            }
        }

        return memo[key] = result;
    }

    int findMinStep(string board, string hand) {
        unordered_map<string, int> memo;
        vector<int> count(26, 0);

        for (char& c: hand)
            ++count[c - 'A'];

        int result = dfs(board, count, memo);

        return result == INT_MAX ? -1 : result;
    }
};
