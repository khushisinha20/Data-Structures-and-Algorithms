//leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int max_sum = INT_MIN;
    
    int maxSum(TreeNode* root) {
        if (!root)
            return 0;
        int max_left_sum = max(0, maxSum(root -> left));
        int max_right_sum = max(0, maxSum(root -> right));
        int curr_max_sum = max_left_sum + max_right_sum + root -> val;
        max_sum = max(curr_max_sum, max_sum);
        return max(root -> val + max_left_sum, root -> val + max_right_sum);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return max_sum;
    }
};