//leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        long res = 0;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            res = max(res, end - start + 1);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front().first;
                long index = q.front().second;
                q.pop();
                if (node -> left)
                    q.push({node -> left, 2 * index + 1});
                if (node -> right)
                    q.push({node -> right, 2 * index + 2});
            }
        }
        return res;
    }
};