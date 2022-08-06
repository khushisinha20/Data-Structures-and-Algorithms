//leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    void mapIndices(unordered_map<int, int>& mp, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
    }
    
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int start, int end, unordered_map<int, int>& indices, int& postorderIndex) {
        if (start > end)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[postorderIndex--]);
        int inorderIndex = indices[root -> val];
        
        root -> right = constructTree(inorder, postorder, inorderIndex + 1, end, indices, postorderIndex);
        root -> left = constructTree(inorder, postorder, start, inorderIndex - 1, indices, postorderIndex);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        mapIndices(mp, inorder);
        int postorderIndex = inorder.size() - 1;
        return constructTree(inorder, postorder, 0, inorder.size() - 1, mp, postorderIndex);
    }
};