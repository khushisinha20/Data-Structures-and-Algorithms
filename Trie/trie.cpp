#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    private:
    Node* root;

    public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); ++i) {
            if (!node -> containsKey(word[i]))
                node -> put(word[i], new Node());
            node = node -> get(word[i]);
        }

        node -> setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node -> containsKey(word[i]))
                return false;
            node = node -> get(word[i]);
        }
        
        return node -> isEnd();
    }

    bool startWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!node -> containsKey(word[i]))
                return false;
            node = node -> get(word[i]);
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << endl;

    cout << "Starts with 'app': " << (trie.startWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'ban': " << (trie.startWith("ban") ? "Yes" : "No") << endl;
    cout << "Starts with 'batman': " << (trie.startWith("batman") ? "Yes" : "No") << endl;

    return 0;
}
