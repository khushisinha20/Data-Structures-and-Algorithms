//leetcode.com/problems/stream-of-characters/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }

    void setEnd() {
        isEndOfWord = true;
    }

    bool isEnd() {
        return isEndOfWord;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* node = root;

        for (int i = word.length() - 1; i >= 0; --i) {
            char ch = word[i];
            if (node -> children.find(ch) == node -> children.end())
                node -> children[ch] = new TrieNode();
            node = node -> children[ch];
        }

        node -> setEnd();
    }

    bool search(vector<char>& stream) {
        TrieNode* node = root;

        for (int i = stream.size() - 1; i >= 0; --i) {
            char ch = stream[i];
            if (node -> children.find(ch) == node -> children.end())
                return false;
            node = node -> children[ch];
            if (node -> isEnd())
                return true;
        }

        return false;
    }
};

class StreamChecker {
public:
    Trie trie;
    vector<char> stream;

    StreamChecker(vector<string>& words) {
        for (auto& word: words)
            trie.insert(word);
    }

    bool query(char letter) {
        stream.push_back(letter);
        return trie.search(stream);
    }
};
