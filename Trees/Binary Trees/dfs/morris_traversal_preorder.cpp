//leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while (curr) {
            if (!curr -> left) {
                preorder.push_back(curr -> val);
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                while (temp -> right && temp -> right != curr) 
                    temp = temp -> right;
                if (!temp -> right) {
                    temp -> right = curr;
                    preorder.push_back(curr -> val);
                    curr = curr -> left;
                } else {
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return preorder;
    }
};