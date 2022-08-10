//leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode* curr = root;
        while (curr) {
            if (curr -> left) {
                TreeNode* left = curr -> left;
                TreeNode* temp = left;
                while (temp -> right)
                    temp = temp -> right;
                temp -> right = curr -> right;
                curr -> left = nullptr;
                curr -> right = left;
            }
            curr = curr -> right;
        }
    }
};