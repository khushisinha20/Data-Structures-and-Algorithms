//leetcode.com/problems/design-add-and-search-words-data-structure/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;

    bool searchHelper(string& word, TrieNode* node, int index) {
        if (!node)
            return false;

        if (index == word.length())
            return node -> isEndOfWord;

        char ch = word[index];
        if (ch == '.') {
            for (auto& [key, child] : node -> children) {
                if (searchHelper(word, child, index + 1))
                    return true;
            }
            return false;
        } else {
            if (node -> children.find(ch) == node -> children.end())
                return false;
            return searchHelper(word, node -> children[ch], index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node -> children.find(ch) == node -> children.end()) {
                node -> children[ch] = new TrieNode();
            }
            node = node -> children[ch];
        }
        node -> isEndOfWord = true;
    }

    bool search(string word) {
        return searchHelper(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
