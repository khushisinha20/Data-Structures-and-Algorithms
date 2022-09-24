//leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        vector<int> preorder;
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            root = nodes.top();
            nodes.pop();
            preorder.push_back(root -> val);
            if (root -> right)
                nodes.push(root -> right);
            if (root -> left)
                nodes.push(root -> left);
        }
        
        return preorder;
    }
};