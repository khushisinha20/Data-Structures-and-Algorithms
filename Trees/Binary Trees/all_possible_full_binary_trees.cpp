//leetcode.com/problems/all-possible-full-binary-trees/

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
    unordered_map<int, vector<TreeNode*>> memo;
    
    vector<TreeNode*> helper(int n) {
        if (n % 2 == 0)
            return {};
        
        if (n == 1) {
            TreeNode* node = new TreeNode();
            return {node};
        }
        
        if (memo.find(n) != memo.end())
            return memo[n];
        
        vector<TreeNode*> result;
        
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n - i - 1);
            
            for (auto& leftNode: left) {
                for (auto& rightNode: right) {
                    TreeNode* root = new TreeNode();
                    root -> left = leftNode;
                    root -> right = rightNode;
                    result.push_back(root);
                }
            }
        }
        
        return memo[n] = result;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};