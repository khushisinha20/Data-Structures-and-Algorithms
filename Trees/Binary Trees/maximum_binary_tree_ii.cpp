//https://leetcode.com/problems/maximum-binary-tree-ii/

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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        
        if (val > root -> val) {
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        } else {
            root -> right = insertIntoMaxTree(root -> right, val);
            return root;
        }
        
        return root;
    }
};
