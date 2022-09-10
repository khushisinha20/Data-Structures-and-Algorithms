//leetcode.com/problems/most-frequent-subtree-sum/

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
    unordered_map<int, int> subtreeSumFrequencies;
    int maximumFrequency = 0;
    
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int sum = root -> val + dfs(root -> left) + dfs(root -> right);
        ++subtreeSumFrequencies[sum];
        maximumFrequency = max(maximumFrequency, subtreeSumFrequencies[sum]); 
        return sum;
    }
    
    vector<int> mostFrequentSubtreeSum(unordered_map<int, int>& subtreeSumFrequencies, int& maximumFrequency) {
        vector<int> mostFrequentSum;
        for (auto frequency: subtreeSumFrequencies)
            if (frequency.second == maximumFrequency)
                mostFrequentSum.push_back(frequency.first);
        return mostFrequentSum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        return mostFrequentSubtreeSum(subtreeSumFrequencies, maximumFrequency);
    }
};