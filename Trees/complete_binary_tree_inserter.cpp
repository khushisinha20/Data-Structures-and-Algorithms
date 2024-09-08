//leetcode.com/problems/complete-binary-tree-inserter/

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

class CBTInserter {
    TreeNode* root;
    int height;
    queue<TreeNode*> lastFullLevel;

    int getHeight(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);

        return 1 + max(leftHeight, rightHeight);
    }

    queue<TreeNode*> getNodesInGivenLevel(TreeNode* root, int level) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        queue<TreeNode*> result;
        int currentLevel = 0;

        while (!nodes.empty()) {
            int size = nodes.size();
            ++currentLevel;
            while (size--) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();

                if (currentLevel == level) {
                    result.push(currentNode);
                }

                if (currentNode -> left)
                    nodes.push(currentNode -> left);

                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
        }

        return result;
    }

    bool isFull(queue<TreeNode*>& nodes, int level) {
        return nodes.size() == pow(2, level - 1);
    }

    bool hasBothChildren(TreeNode* node) {
        return node -> left && node ->  right;
    }

public:
    CBTInserter(TreeNode* root) : root(root) {
        height = getHeight(root);
        queue<TreeNode*> lastLevel = getNodesInGivenLevel(root, height);
        queue<TreeNode*> secondLastLevel = getNodesInGivenLevel(root, height - 1);

        if (isFull(lastLevel, height)) {
            lastFullLevel = lastLevel;
        } else {
            lastFullLevel = secondLastLevel;
            while (!lastLevel.empty()) {
                lastFullLevel.push(lastLevel.front());
                lastLevel.pop();
            }
        }

        while (!lastFullLevel.empty()) {
            TreeNode* node = lastFullLevel.front();
            if (!hasBothChildren(node))
                break;
            lastFullLevel.pop();
        }
    }

    int insert(int val) {
        TreeNode* node = lastFullLevel.front();
        if (!node -> left) {
            node -> left = new TreeNode(val);
            lastFullLevel.push(node -> left);
        } else {
            node -> right = new TreeNode(val);
            lastFullLevel.push(node -> right);
        }

        if (hasBothChildren(node))
            lastFullLevel.pop();

        return node -> val;
    }

    TreeNode* get_root() {
        return root;
    }
};
