//leetcode.com/problems/deepest-leaves-sum/

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
    int sum = 0;
    
    int maxDepth(TreeNode* node) {
        if (!node)
            return 0;
        return 1 + max(maxDepth(node -> left), maxDepth(node -> right));
    }
    
    void lastLevelSum(TreeNode* node, int currentDepth, int maxDepth) {
        if (!node)
            return;
        
        if (currentDepth == maxDepth) 
            sum += node -> val;
        lastLevelSum(node -> left, currentDepth + 1, maxDepth);
        lastLevelSum(node -> right, currentDepth + 1, maxDepth);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int totalLevels = maxDepth(root);
        lastLevelSum(root, 1, totalLevels);
        return sum;
    }
};