//leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
    int MOD = 1000000007;
    long long maxProductOfSums = 0;
    
    long long sumOfAllNodes(TreeNode* node) {
        if (!node)
            return 0;
        
        node -> val += sumOfAllNodes(node -> left);
        node -> val += sumOfAllNodes(node -> right);
        
        return node -> val;
    }
    
    void maximizeProduct(TreeNode* node, long long& totalSum) {
        if (!node)
            return;
        
        long long subtreeSum1 = totalSum - node -> val;
        long long subtreeSum2 = node -> val;
        maxProductOfSums = max(maxProductOfSums, subtreeSum1 * subtreeSum2);
        
        maximizeProduct(node -> left, totalSum);
        maximizeProduct(node -> right, totalSum);
    }
    
    int maxProduct(TreeNode* root) {
        long long totalSum = sumOfAllNodes(root);
        maximizeProduct(root, totalSum);
        return maxProductOfSums % MOD;
    }
};