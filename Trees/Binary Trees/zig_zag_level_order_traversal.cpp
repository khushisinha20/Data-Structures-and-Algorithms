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
        vector<vector<int>> res;
        if (!root)
            return res;
        bool reverse = true;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> level_nodes;
            deque<TreeNode*> dq;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                level_nodes.push_back(node -> val);
                q.pop_front();
                if (reverse) {
                    if (node -> left)
                        dq.push_front(node -> left);
                    if (node -> right)
                        dq.push_front(node -> right);
                } else {
                    if (node -> right)
                        dq.push_front(node -> right);
                    if (node -> left)
                        dq.push_front(node -> left);
                }
            }
            q.insert(q.end(), dq.begin(), dq.end());
            res.push_back(level_nodes);
            reverse = !reverse;
        }
        return res;
    }
};