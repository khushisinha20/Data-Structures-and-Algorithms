//leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        
        int largest = INT_MIN;
        int currentLargest = INT_MIN;
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> largestInEachLevel;
        
        while (!nodes.empty()) {
            largest = INT_MIN;
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                largest = max(largest, currentNode -> val);
                if (currentNode -> left)
                    nodes.push(currentNode -> left);
                if (currentNode -> right)
                    nodes.push(currentNode -> right);
            }
            largestInEachLevel.push_back(largest);
        }
        return largestInEachLevel;
    }
};