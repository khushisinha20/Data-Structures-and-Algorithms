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
        TreeNode* curr = root;
        
        while (true) {
            if (curr) {
                nodes.push(curr);
                curr = curr -> left;
            } else {
                if (nodes.empty())
                    break;
                else {
                    curr = nodes.top();
                    inorder.push_back(curr -> val);
                    nodes.pop();
                    curr = curr -> right;
                }
            }
        }
        return inorder;
    }
};