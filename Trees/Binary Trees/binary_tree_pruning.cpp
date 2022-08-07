//leetcode.com/problems/binary-tree-pruning/

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
    int removeSubtreeContainingZero(TreeNode* root) {
        if (!root)
            return 0;
        
        int zeroesInLeftSubtree = removeSubtreeContainingZero(root -> left);
        int zeroesInRightSubtree = removeSubtreeContainingZero(root -> right);
        
        if (zeroesInLeftSubtree == 0)
            root -> left = nullptr;
        
        if (zeroesInRightSubtree == 0)
            root -> right = nullptr;
        
        return zeroesInLeftSubtree + zeroesInRightSubtree + root -> val;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (removeSubtreeContainingZero(root) == 0)
            return nullptr;
        return root;
    }
};