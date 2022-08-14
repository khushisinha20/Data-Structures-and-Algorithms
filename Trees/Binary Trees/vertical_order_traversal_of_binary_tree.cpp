//leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    void dfs(TreeNode* root, int horizontal_position, int level, map<int, vector<pair<int, int>>>& mp) {
        if (!root)
            return;
        dfs(root -> left, horizontal_position - 1, level + 1, mp);
        mp[horizontal_position].push_back({level, root -> val});
        dfs(root -> right, horizontal_position + 1, level + 1, mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        dfs(root, 0, 0, mp);
        vector<vector<int>> res;
        for (auto it: mp) {
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            for (auto i: it.second)
                temp.push_back(i.second);
            res.push_back(temp);
        }
        return res;
    }
};