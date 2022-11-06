//leetcode.com/problems/convert-bst-to-greater-tree/

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
    int rightSubtreeSum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return nullptr;
        convertBST(root -> right);
        rightSubtreeSum += root -> val;
        root -> val = rightSubtreeSum;
        convertBST(root -> left);
        return root;
    }
};