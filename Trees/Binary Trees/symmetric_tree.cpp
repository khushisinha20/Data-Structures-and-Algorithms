//leetcode.com/problems/symmetric-tree/

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
    bool isSymmetricTree(TreeNode* left, TreeNode* right) {
        if (!left || !right)
            return left == right;
        if (left -> val != right -> val)
            return false;
        return (isSymmetricTree(left -> left, right -> right)) && (isSymmetricTree(left -> right, right -> left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetricTree(root -> left, root -> right);
    }
};