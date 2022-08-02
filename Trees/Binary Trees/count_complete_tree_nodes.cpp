//leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int count_of_right_nodes = 1;
        int count_of_left_nodes = 1;
        TreeNode* right_node = root;
        TreeNode* left_node = root;
        while (left_node -> left) {
            left_node = left_node -> left;
            ++count_of_left_nodes;
        }
        while (right_node -> right) {
            right_node = right_node -> right;
            ++count_of_right_nodes;
        }
        
        if (count_of_left_nodes == count_of_right_nodes)
            return pow(2, count_of_left_nodes) - 1;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};