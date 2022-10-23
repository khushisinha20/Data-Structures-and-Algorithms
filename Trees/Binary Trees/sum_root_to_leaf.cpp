//leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void dfs(TreeNode* root, int& result, int sum) {
        sum += root -> val;
        if (!root -> left && !root -> right)
            result += sum;
        if (root -> left)
            dfs(root -> left, result, sum * 10);
        if (root -> right)
            dfs(root -> right, result, sum * 10);
        sum -= root -> val;
    }
    
    int sumNumbers(TreeNode* root) {
        int result = 0;
        dfs(root, result, 0);
        return result;
    }
};