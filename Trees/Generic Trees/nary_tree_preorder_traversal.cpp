//leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void traversal(Node* root, vector<int>& ans) {
        if (!root)
            return;
        ans.push_back(root -> val);
        for (auto childNode: root -> children)
            traversal(childNode, ans);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
};