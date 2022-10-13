//leetcode.com/problems/add-one-row-to-tree/

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
    void bfs(TreeNode* root, int depth, queue<TreeNode*>& previousLevel) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int level = 1;
        if (depth == 2) {
            previousLevel.push(root);
            return;
        }
        
        while (!nodes.empty()) {
            int size = nodes.size();
            ++level;
            for (int i = 0; i < size; ++i) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                if (level == depth)
                    previousLevel.push(currentNode);
                if (currentNode -> left)
                    nodes.push(currentNode -> left);
                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
        }
    }
    
    void addRow(TreeNode* root, int val, queue<TreeNode*>& nodes) {
        while (!nodes.empty()) {
            TreeNode* currentNode = nodes.front();
            cout << currentNode -> val << " ";
            nodes.pop();
            TreeNode* leftSubtreeRoot = new TreeNode(val);
            TreeNode* rightSubtreeRoot = new TreeNode(val);
            leftSubtreeRoot -> left = currentNode -> left;
            currentNode -> left = leftSubtreeRoot;
            rightSubtreeRoot -> right = currentNode -> right;
            currentNode -> right = rightSubtreeRoot;
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        queue<TreeNode*> previousLevel;
        bfs(root, depth, previousLevel);
        addRow(root, val, previousLevel);
        return root;
    }
};