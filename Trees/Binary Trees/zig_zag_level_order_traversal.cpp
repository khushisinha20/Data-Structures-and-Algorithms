//leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        TreeNode* current = root;
        queue<TreeNode*> nodes;
        
        nodes.push(current);
        vector<vector<int>> result;
        bool leftToRight = true;
        
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> level(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                int index = leftToRight ? i : size -i - 1;
                level[index] = currentNode -> val;
                
                if (currentNode -> left)
                    nodes.push(currentNode -> left);
                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
            leftToRight ^= 1;
            result.push_back(level);
        }
        return result;
    }
};