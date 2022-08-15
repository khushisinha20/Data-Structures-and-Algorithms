//leetcode.com/problems/same-tree/

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
    bool isEqual(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p && q)
            return false;
        if (p && !q)
            return false;
        if (p -> val == q -> val)
            return true;
        return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!isEqual(p, q))
            return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();
            if (!isEqual(node1, node2))
                return false;
            if (node1 && node2) {
                if (!isEqual(node1 -> left, node2 -> left))
                    return false;
                if (node1 -> left && node2 -> left) {
                    q1.push(node1 -> left);
                    q2.push(node2 -> left);
                }
                if (!isEqual(node1 -> right, node2 -> right))
                    return false;
                if (node1 -> right && node2 -> right) {
                    q1.push(node1 -> right);
                    q2.push(node2 -> right);
                }
            }
        }
        return true;
    }
};