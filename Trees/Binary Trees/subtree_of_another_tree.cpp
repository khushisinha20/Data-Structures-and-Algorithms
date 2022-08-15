//leetcode.com/problems/subtree-of-another-tree/

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
    bool isSameTree(TreeNode* curr, TreeNode* subRoot) {
        if (!curr && !subRoot)
            return true;
        if (curr && !subRoot)
            return false;
        if (!curr && subRoot)
            return false;
        if (curr -> val != subRoot -> val)
            return false;
        return isSameTree(curr -> left, subRoot -> left) && isSameTree(curr -> right, subRoot -> right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        else if (isSameTree(root, subRoot))
            return true;
        else
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};