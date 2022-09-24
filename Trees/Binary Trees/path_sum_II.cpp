//leetcode.com/problems/path-sum-ii/

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
    void dfs(TreeNode* root, vector<vector<int>>& paths, int& targetSum, int currentSum, vector<int> currentPath) {
        if (!root)
            return;
        
        currentSum += root -> val;
        currentPath.push_back(root -> val);
        
        if (!root -> left && !root -> right) {
            if (currentSum == targetSum)
                paths.push_back(currentPath);
            return;
        }
        
        dfs(root -> left, paths, targetSum, currentSum, currentPath);
        dfs(root -> right, paths, targetSum, currentSum, currentPath);
        
        currentSum -= root -> val;
        currentPath.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        int currentSum = 0;
        vector<int> currentPath;
        dfs(root, paths, targetSum, currentSum, currentPath);
        return paths;
    }
};