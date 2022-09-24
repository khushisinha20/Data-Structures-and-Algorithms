//leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        stack<TreeNode*> nodes;
        vector<int> inorder;
        while (!nodes.empty() || root) {
            while (root) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            nodes.pop();
            inorder.push_back(root -> val);
            root = root -> right;
        }
        return inorder;
    }
};