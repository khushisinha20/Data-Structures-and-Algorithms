//leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average_level_sum;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            double level_sum = 0;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node -> left)
                    q.push(node -> left);
                if (node -> right)
                    q.push(node -> right);
                level_sum += node -> val;
            }
            average_level_sum.push_back(level_sum / size);
        }
        return average_level_sum;
    }
};