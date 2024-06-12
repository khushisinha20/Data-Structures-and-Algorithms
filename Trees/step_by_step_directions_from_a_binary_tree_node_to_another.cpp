//leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

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
    TreeNode* getNode(TreeNode* node, int value) {
        if (!node)
            return nullptr;

        if (node -> val == value)
            return node;

        TreeNode* leftResult = getNode(node -> left, value);

        if (leftResult)
            return leftResult;

        return getNode(node -> right, value);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root or root -> val == p -> val or root -> val == q -> val)
            return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if (!left)
            return right;
        else if (!right)
            return left;
        return root;
    }

   bool findPath(TreeNode* root, int value, string& path) {
        if (!root)
            return false;

        if (root -> val == value)
            return true;

        path.push_back('L');
        if (findPath(root -> left, value, path))
            return true;
        path.pop_back();

        path.push_back('R');
        if (findPath(root -> right, value, path))
            return true;
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = lowestCommonAncestor(root, getNode(root, startValue), getNode(root, destValue));
        string startPath;
        string destPath;
        findPath(lca, startValue, startPath);
        findPath(lca, destValue, destPath);

        for (auto& direction: startPath)
            direction = 'U';

        return startPath + destPath;
    }
};
