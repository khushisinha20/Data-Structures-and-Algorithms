//leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> createTree(vector<int>& parents) {
        int n = parents.size();
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; ++i)
            tree[parents[i]].push_back(i);

        return tree;
    }

    void collectGeneticValues(int node, vector<vector<int>>& tree, vector<int>& nums, unordered_set<int>& geneticValues) {
        if (geneticValues.count(nums[node]))
            return;

        geneticValues.insert(nums[node]);
        for (int child: tree[node])
            collectGeneticValues(child, tree, nums, geneticValues);
    }

    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<vector<int>> tree = createTree(parents);
        vector<int> ans(n, 1);
        vector<bool> seen(100001, false);

        int nodeWithOne = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                nodeWithOne = i;
                break;
            }
        }

        if (nodeWithOne == -1)
            return ans;

        int smallestMissing = 1;
        unordered_set<int> geneticValues;
        for (int node = nodeWithOne; node != -1; node = parents[node]) {
            collectGeneticValues(node, tree, nums, geneticValues);
            while (geneticValues.count(smallestMissing)) {
                ++smallestMissing;
            }
            ans[node] = smallestMissing;
        }

        return ans;
    }
};
