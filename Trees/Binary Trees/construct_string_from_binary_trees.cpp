//leetcode.com/problems/construct-string-from-binary-tree/

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
    void dfs(TreeNode* root, string& res) {
        res += to_string(root -> val);
        
        if (!root -> left && !root -> right)
            return;
        
        if (root -> left) {
            res += '(';
            dfs(root -> left, res);
            res += ')';
        } else 
            res += "()";
        
        if (root -> right) {
            res += '(';
            dfs(root -> right, res);
            res += ')';
        } 
    }
    
    string tree2str(TreeNode* root) {
        string res = "";
        dfs(root, res);
        return res;
    }
};