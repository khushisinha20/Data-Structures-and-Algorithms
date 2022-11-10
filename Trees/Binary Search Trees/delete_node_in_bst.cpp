//leetcode.com/problems/delete-node-in-a-bst/

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
    int getSuccessor(TreeNode* node) {
        node = node -> right;
        while (node && node -> left) 
            node = node -> left;
        return node -> val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        
        if (root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else if (root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else {
            if (!root -> left) {
                TreeNode* temp = root -> right;
                TreeNode* curr = root;
                delete curr;
                return temp;
            } else if (!root -> right) {
                TreeNode* temp = root -> left;
                TreeNode* curr = root;
                delete curr;
                return temp;
            } else {
                int successor = getSuccessor(root);
                root -> val = successor;
                root -> right = deleteNode(root -> right, successor);
            }
        }
        return root;
    }
};