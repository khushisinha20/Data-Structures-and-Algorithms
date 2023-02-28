//practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

class Solution{
public:
    int i = 0;

    void solve(Node* root, string str) {
        if (i < str.length() && isdigit(str[i])) {
            int value = 0;
            while (i < str.length() && isdigit(str[i])) {
                value *= 10;
                value += (str[i] - '0');
                ++i;
            }
            root -> data = value;
        }
        
        if (i < str.length() && str[i] == '(') {
            root -> left = new Node(0);
            ++i;
            solve(root -> left, str);
        }
        
        if (i < str.length() && str[i] == '(') {
            root -> right = new Node(0);
            ++i;
            solve(root -> right, str);
        }
        
        if (i >= str.length() || str[i] == ')') {
            ++i;
            return;
        }
    }

    Node *treeFromString(string str) {
        Node* root = new Node(0);
        solve(root, str);
        return root;
    }
};