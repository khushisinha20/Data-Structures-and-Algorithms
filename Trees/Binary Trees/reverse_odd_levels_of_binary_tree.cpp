//leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int current_level = -1;
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> current_level_nodes;
        queue<TreeNode*> current_level_queue;
        while (!nodes.empty()) {
            ++current_level;
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* front_node = nodes.front();
                nodes.pop();
                if (current_level % 2 == 1) {
                    current_level_nodes.push_back(front_node -> val);
                    current_level_queue.push(front_node);
                }
                if (front_node -> left && front_node -> right) {
                    nodes.push(front_node -> left);
                    nodes.push(front_node -> right);
                }
            }
            if (current_level % 2 == 1) {
                int index = 0;
                reverse(current_level_nodes.begin(), current_level_nodes.end());
                while (!current_level_queue.empty()) {
                    current_level_queue.front() -> val = current_level_nodes[index++];
                    current_level_queue.pop();
                }
            }
        }
        return root;
    }
};