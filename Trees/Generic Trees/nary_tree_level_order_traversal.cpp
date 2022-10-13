//leetcode.com/problems/n-ary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};
        vector<vector<int>> level_order;
        queue<Node*> nodes;
        Node* curr = root;
        nodes.push(curr);
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> current_level;
            for (int i = 0; i < size; ++i) {
                curr = nodes.front();
                nodes.pop();
                current_level.push_back(curr -> val);
                for (auto childNode: curr -> children)
                    nodes.push(childNode);
            }
            level_order.push_back(current_level);
        }
        return level_order;
    }
};