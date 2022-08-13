//leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

class BSTIterator {
    private:
    stack<TreeNode*> s;
    bool reverse = true;
    
    public:
    BSTIterator(TreeNode* root, bool is_forward) {
        reverse = is_forward;
        pushIntoStack(root);
    }
    
    public:
    int next() {
        TreeNode* last_visited_node = s.top();
        s.pop();
        if (reverse)
            pushIntoStack(last_visited_node -> left);
        else
            pushIntoStack(last_visited_node -> right);
        return last_visited_node -> val;
    }
    
    private:
    void pushIntoStack(TreeNode* node) {
        while (node) {
            s.push(node);
            if (reverse) 
                node = node -> right;
            else
                node = node -> left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root, false);
        BSTIterator right(root, true);
        
        int start = left.next();
        int end = right.next();
        
        while (start < end) {
            if (start + end == k)
                return true;
            else if (start + end < k)
                start = left.next();
            else
                end = right.next();
        }
        return false;
    }
};