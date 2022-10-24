//leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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

class FindElements {
public:
    unordered_set<int> nodes;
    
    void recoverOriginalTree(TreeNode* root, int x) {
        if (!root)
            return;
        root -> val = x;
        nodes.insert(x);
        recoverOriginalTree(root -> left, 2 * x + 1);
        recoverOriginalTree(root -> right, 2 * x + 2);
    }
    
    FindElements(TreeNode* root) {
        recoverOriginalTree(root, 0);
    }
    
    bool find(int target) {
        return nodes.find(target) != nodes.end();
    }
};