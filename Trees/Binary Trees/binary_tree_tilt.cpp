//leetcode.com/problems/binary-tree-tilt/

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
    int result = 0;
    
    int helper(TreeNode* root) {
        int left_sum = root -> left ? helper(root -> left) : 0;
        int right_sum = root -> right ? helper(root -> right) : 0;
        result += abs(left_sum - right_sum);
        return left_sum + right_sum + root -> val;
    }
    
    int findTilt(TreeNode* root) {
        if (root)
           helper(root);
        return result;
    }
};