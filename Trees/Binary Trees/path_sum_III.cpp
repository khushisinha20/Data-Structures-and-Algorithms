//leetcode.com/problems/path-sum-iii/

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
    int result = 0;
    unordered_map<long, int> mp;
    
    void preorder(TreeNode* root, long current_sum, int& target_sum) {
        if (!root)
            return;
        current_sum += root -> val;
        if (mp.find(current_sum - target_sum) != mp.end())
            result += mp[current_sum - target_sum];
        ++mp[current_sum];
        preorder(root -> left, current_sum, target_sum);
        preorder(root -> right, current_sum, target_sum);
        --mp[current_sum];
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        mp.insert({0, 1});
        preorder(root, 0, targetSum);
        return result;
    }
};