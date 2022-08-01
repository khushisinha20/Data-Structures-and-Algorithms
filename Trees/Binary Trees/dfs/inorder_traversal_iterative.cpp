//leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return {};
        
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (true) {
            while (curr) {
                s.push(curr);
                curr = curr -> left;
            }
            if (s.empty())
                break;
            curr = s.top();
            inorder.push_back(curr -> val);
            s.pop();
            curr = curr -> right;
        }
        
        return inorder;
    }
};