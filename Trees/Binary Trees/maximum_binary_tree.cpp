//https://leetcode.com/problems/maximum-binary-tree/

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
    int getMaximumIndex(vector<int>& nums, int left, int right) {
        int maxNum = -1;
        int maxIndex = -1;
        
        for (int i = left; i <= right; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        }
        
        return maxIndex;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (right < left)
            return nullptr;
        
        int maxIndex = getMaximumIndex(nums, left, right);
        TreeNode* root = new TreeNode(nums[maxIndex]);
        root -> left = constructMaximumBinaryTree(nums, left, maxIndex - 1);
        root -> right = constructMaximumBinaryTree(nums, maxIndex + 1, right);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    }
};