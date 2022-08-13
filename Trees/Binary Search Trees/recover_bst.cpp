//leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root -> left);
        if (prev && prev -> val > root -> val) {
            if (!first) {
                first = prev;
                middle = root;
            } else 
                last = root;
        }
        prev = root;
        inorder(root -> right);
    }
    
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        first = nullptr;
        middle = nullptr;
        last = nullptr;
        inorder(root);
        if (first && last)
            swap(first -> val, last -> val);
        else if (first && middle)
            swap(first -> val, middle -> val);
    }
};