//leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    void dfs(TreeNode* node, TreeNode* root, int& second_smallest) {
        if (!node)
            return;
        if (root -> val < node -> val && (second_smallest == NULL || node -> val < second_smallest))
            second_smallest = node -> val;
        dfs(node -> left, root, second_smallest);
        dfs(node -> right, root, second_smallest);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int second_smallest = NULL;
        TreeNode* node = root;
        dfs(node, root, second_smallest);
        if (second_smallest == NULL)
            return -1;
        return second_smallest;
    }
};