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
    int findMax(TreeNode* root) {
        if (!root -> right)
            return root -> val;
        return findMax(root -> right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        if (!curr)
            return nullptr;
        
        if (curr -> val < key) 
            curr -> right = deleteNode(curr -> right, key);
        else if (curr -> val > key)
            curr -> left = deleteNode(curr -> left, key);
        else {
            if (curr -> left && curr -> right) {
                int left_max = findMax(root -> left);
                curr -> val = left_max;
                curr -> left = deleteNode(curr -> left, left_max);
                return curr;
            } else if (curr -> left) 
                return curr -> left;
             else if (curr -> right) 
                return curr -> right;
             else 
                return nullptr;
        }
        return curr;
    }
};