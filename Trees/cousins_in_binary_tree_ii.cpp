//leetcode.com/problems/cousins-in-binary-tree-ii/

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
    int findSiblingSum(TreeNode* node) {
        int siblingSum = 0;
        if (node -> left)
            siblingSum += node -> left -> val;
        if (node -> right)
            siblingSum += node -> right -> val;
        return siblingSum;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root)
            return nullptr;

        queue<TreeNode*> nodes;
        nodes.push(root);
        root -> val = 0;

        while (!nodes.empty()) {
            int levelSize = nodes.size();
            int nextLevelSum = 0;
            vector<TreeNode*> currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                currentLevel.push_back(currentNode);

                if (currentNode -> left) {
                    nextLevelSum += currentNode -> left -> val;
                    nodes.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    nextLevelSum += currentNode -> right -> val;
                    nodes.push(currentNode -> right);
                }
            }

            for (TreeNode* node: currentLevel) {
                int siblingSum = findSiblingSum(node);
                if (node -> left)
                    node -> left -> val = nextLevelSum - siblingSum;
                if (node -> right)
                    node -> right -> val = nextLevelSum - siblingSum;
            }
        }

        return root;
    }
};
