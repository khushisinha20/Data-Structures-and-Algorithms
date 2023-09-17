//leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    int getDepth(TreeNode* node) {
        if (!node)
            return 0;
        
        return 1 + max(getDepth(node -> left), getDepth(node -> right));
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root)
            return root;
        
        int leftDepth = getDepth(root -> left);
        int rightDepth = getDepth(root -> right);
        
        if (leftDepth == rightDepth)
            return root;
        
        if (leftDepth > rightDepth)
            return subtreeWithAllDeepest(root -> left);
        return subtreeWithAllDeepest(root -> right);
    }
};