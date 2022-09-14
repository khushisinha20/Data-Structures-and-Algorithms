//leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    void dfs(TreeNode* root, vector<int> frequencies, int& pseudoPalindromeCount) {
        if (!root -> left && !root -> right) {
            ++frequencies[root -> val - 1];
            int oddFrequency = 0;
            for (auto frequency: frequencies) 
                if (frequency % 2 == 1)
                    ++oddFrequency;
            if (oddFrequency <= 1)
                ++pseudoPalindromeCount;
            return;
        }
        ++frequencies[root -> val - 1];
        if (root -> left)
            dfs(root -> left, frequencies, pseudoPalindromeCount);
        if (root -> right)
            dfs(root -> right, frequencies, pseudoPalindromeCount);
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> frequencies(9, 0);
        int pseudoPalindromeCount = 0;
        dfs(root, frequencies, pseudoPalindromeCount);
        return pseudoPalindromeCount;
    }
};