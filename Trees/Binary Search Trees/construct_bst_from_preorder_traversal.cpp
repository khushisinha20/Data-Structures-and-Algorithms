//leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* buildBST(int& index, vector<int>& preorder, int upper_bound) {
        if (index == preorder.size() || preorder[index] > upper_bound)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[index++]);
        root -> left = buildBST(index, preorder, root -> val);
        root -> right = buildBST(index, preorder, upper_bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(index, preorder, INT_MAX);
    }
};