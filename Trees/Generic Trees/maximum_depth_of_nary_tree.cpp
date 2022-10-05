//leetcode.com/problems/maximum-depth-of-n-ary-tree/

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
    int maxDepth(Node* root) {
        if (!root)
            return 0;
        int level = 0;
        queue<Node*> nodes;
        Node* curr = root;
        nodes.push(curr);
        while (!nodes.empty()) {
            int size = nodes.size();
            ++level;
            for (int i = 0; i < size; ++i) {
                curr = nodes.front();
                nodes.pop();
                for (auto childNode: curr -> children)
                    nodes.push(childNode);
            }
        }
        return level;
    }
};