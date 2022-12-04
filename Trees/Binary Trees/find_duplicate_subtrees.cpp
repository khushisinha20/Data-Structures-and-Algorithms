//leetcode.com/problems/find-duplicate-subtrees/

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
    unordered_map<string, int> freq;
    vector<TreeNode*> res;
    
    string dfs(TreeNode* root) {
        if (!root)
            return "";
        
        string left = dfs(root -> left);
        string right = dfs(root -> right);
        string curr = to_string(root -> val) + " " + left + " " + right;
        
        if (freq[curr] == 1)
            res.push_back(root);
        
        ++freq[curr];
        return curr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string dummy = dfs(root);
        return res;
    }
};