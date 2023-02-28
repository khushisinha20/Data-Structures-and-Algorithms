//leetcode.com/problems/balanced-binary-tree/

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
    pair<bool, int> dfs(TreeNode* node) {
        if (!node)
            return {true, 0};
        
        auto left = dfs(node -> left);
        auto right = dfs(node -> right);
        
        bool isBalanced = left.first and right.first and abs(left.second - right.second) <= 1;
        
        return {isBalanced, 1 + max(left.second, right.second)};
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        return dfs(root).first;
    }
};