//leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int preorderIndex = 0;
    
    void mapIndices(unordered_map<int, int>& mp, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
    }
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end, unordered_map<int, int>& indices) {
        if (start > end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderIndex++]);
        int inorderIndex = 0;
        inorderIndex = indices[root -> val];
        
        root -> left = constructTree(preorder, inorder, start, inorderIndex - 1, indices);
        root -> right = constructTree(preorder, inorder, inorderIndex + 1, end, indices);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;
        mapIndices(indices, inorder);
        int start = 0;
        int end = inorder.size() - 1;
        return constructTree(preorder, inorder, start, end, indices);
    }
};