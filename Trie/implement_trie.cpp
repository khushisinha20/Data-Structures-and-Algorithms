//leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
public:
    TrieNode() {
        isEndOfWord = false;
    }
    
    bool containsKey(char letter) {
        return children.find(letter) != children.end();
    }
    
    TrieNode* get(char letter) {
        return children.at(letter);
    }
    
    void put(char letter, TrieNode* node) {
        children[letter] = node;
    }
    
    void setEnd() {
        isEndOfWord = true;
    }
    
    bool isEnd() {
        return isEndOfWord;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char& letter: word) {
            if (!node -> containsKey(letter)) {
                node -> put(letter, new TrieNode());
            }
            node = node -> get(letter);
        }
        node -> setEnd();
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char& letter: word) {
            if (!node -> containsKey(letter))
                return false;
            node = node -> get(letter);
        }
        return node -> isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char& letter: prefix) {
            if (!node -> containsKey(letter))
                return false;
            node = node -> get(letter);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */