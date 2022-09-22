//leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode* bottomLeftValue = NULL;
        nodes.push(root);
        
        while (!nodes.empty()) {
            int size = nodes.size();
            bottomLeftValue = NULL;
            while (size--) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                if (!bottomLeftValue)
                    bottomLeftValue = currentNode;
                if (currentNode -> left)
                    nodes.push(currentNode -> left);
                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
        }
        return bottomLeftValue -> val;
    }
};