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
        TreeNode* curr = root;
        stack<TreeNode*> nodes;
        nodes.push(curr);
        vector<int> preorder;
        
        while (!nodes.empty()) {
            TreeNode* currentRoot = nodes.top();
            preorder.push_back(currentRoot -> val);
            nodes.pop();
            if (currentRoot -> right)
                nodes.push(currentRoot -> right);
            if (currentRoot -> left)
                nodes.push(currentRoot -> left);
        }
        
        return preorder;
    }
};