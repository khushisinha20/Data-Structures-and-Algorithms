//leetcode.com/problems/unique-binary-search-trees-ii/

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
    map<pair<int, int>, vector<TreeNode*>> memo;
    
    vector<TreeNode*> generateTreesUtil(int start, int end) {
        if (start > end)
            return {nullptr};
        
        if (memo.find({start, end}) != memo.end())
            return memo[{start, end}];
        
        if (start == end)
            return {new TreeNode(start)};
        
        vector<TreeNode*> result;
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftList = generateTreesUtil(start, i - 1);
            vector<TreeNode*> rightList = generateTreesUtil(i + 1, end);
            
            for (TreeNode* leftRoot: leftList) {
                for (TreeNode* rightRoot: rightList) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = leftRoot;
                    root -> right = rightRoot;
                    
                    result.push_back(root);
                }
            }
        }
        
        return memo[{start, end}] = result;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesUtil(1, n);
    }
};