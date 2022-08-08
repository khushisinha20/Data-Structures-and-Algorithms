//leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root -> val == p -> val || root -> val == q -> val)
            return root;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;
        if (root -> left)
            left = lowestCommonAncestor(root -> left, p, q);
        if (root -> right)
            right = lowestCommonAncestor(root -> right, p, q);
        if (!left && !right)
            return nullptr;
        if (left && right)
            return root;
        if (left && !right)
            return left;
        if (!left && right)
            return right;
        return root;
    }
};