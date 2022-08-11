//leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int res = 0;
        while (curr != nullptr) {
            if (curr -> left == nullptr) {
                if (--k == 0)
                    res = curr -> val;
                curr = curr -> right;
            } else {
                TreeNode* temp = curr -> left;
                while (temp -> right != nullptr && temp -> right != curr) {
                    temp = temp -> right;
                }
                if (temp -> right == nullptr) {
                    temp -> right = curr;
                    curr = curr -> left;
                } else {
                    if (--k == 0)
                        res = curr -> val;
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
            }
        }
        return res;
    }
};