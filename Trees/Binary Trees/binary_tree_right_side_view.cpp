//leetcode.com/problems/binary-tree-right-side-view/

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
    void dfs(vector<int>& rightView, TreeNode* node, int level) {
        if (!node)
            return;
        
        if (level == rightView.size())
            rightView.push_back(node -> val);
        dfs(rightView, node -> right, level + 1);
        dfs(rightView, node -> left, level + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        vector<int> rightView;
        dfs(rightView, root, 0);
        return rightView;
    }
};