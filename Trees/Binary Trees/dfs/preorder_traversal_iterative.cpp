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
        vector<int> res;
        if (!root)
            return res;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* root = s.top();
            s.pop();
            res.push_back(root -> val);
            if (root -> right)
                s.push(root -> right);
            if (root -> left)
                s.push(root -> left);
        }
        return res;
    }
};