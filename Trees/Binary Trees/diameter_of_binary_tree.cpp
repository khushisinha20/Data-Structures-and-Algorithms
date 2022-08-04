//leetcode.com/problems/diameter-of-binary-tree/

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
    int heightOfBinaryTree(TreeNode* root, int& res) {
        if (!root)
            return 0;
        int left_height = heightOfBinaryTree(root -> left, res);
        int right_height = heightOfBinaryTree(root -> right, res);
        res = max(res, left_height + right_height);
        return 1 + max(left_height, right_height);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int height = heightOfBinaryTree(root, res);
        return res;
    }
};