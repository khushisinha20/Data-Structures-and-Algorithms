//leetcode.com/problems/sum-of-left-leaves/

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
    int sum = 0;
    
    void helper(TreeNode* node) {
        if (!node)
            return;
        if (node -> left && !node -> left -> left && !node -> left -> right)
            sum += node -> left -> val;
        helper(node -> left);
        helper(node -> right);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};