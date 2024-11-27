//leetcode.com/problems/word-search-ii/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;

public:
    TrieNode() {
        isEnd = false;
    }

    void setEndOfWord() {
        isEnd = true;
    }

    bool isEndOfWord() {
        return isEnd;
    }

    unordered_map<char, TrieNode*>& getChildren() {
        return children;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    TrieNode* getRoot() {
        return root;
    }

    void insert(string& word) {
        TrieNode* node = root;
        for (char letter : word) {
            if (!node -> getChildren().count(letter)) {
                node -> getChildren()[letter] = new TrieNode();
            }
            node = node -> getChildren()[letter];
        }
        node -> setEndOfWord();
    }
};

class Solution {
public:
    bool isWithinBounds(int row, int col, vector<vector<char>>& board) {
        return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, TrieNode* node, string& currentWord, unordered_set<string>& resultSet) {
        if (!isWithinBounds(row, col, board) || visited[row][col])
            return;

        char letter = board[row][col];
        if (!node -> getChildren().count(letter))
            return;

        node = node -> getChildren()[letter];
        currentWord.push_back(letter);

        visited[row][col] = true;
        if (node -> isEndOfWord())
            resultSet.insert(currentWord);

        dfs(board, visited, row - 1, col, node, currentWord, resultSet);
        dfs(board, visited, row, col - 1, node, currentWord, resultSet);
        dfs(board, visited, row + 1, col, node, currentWord, resultSet);
        dfs(board, visited, row, col + 1, node, currentWord, resultSet);

        currentWord.pop_back();
        visited[row][col] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (auto& word : words)
            trie.insert(word);

        unordered_set<string> resultSet;
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        string currentWord;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(board, visited, i, j, trie.getRoot(), currentWord, resultSet);
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }
};

