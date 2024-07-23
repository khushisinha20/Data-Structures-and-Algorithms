//leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = find(parent[node]);
    }

    void unionOfNodes(int u, int v) {
        int parentOfU = find(u);
        int parentOfV = find(v);

        if (parentOfU == parentOfV)
            return;

        if (rank[parentOfU] < rank[parentOfV])
            parent[parentOfU] = parentOfV;
        else if (rank[parentOfV] < rank[parentOfU])
            parent[parentOfV] = parentOfU;
        else {
            parent[parentOfV] = parentOfU;
            ++rank[parentOfU];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < n; ++i)
            indexedNums.push_back({nums[i], i});
        sort(indexedNums.begin(), indexedNums.end());

        vector<pair<int, int>> pairs;
        for (int i = 1; i < n; ++i) {
            if (indexedNums[i].first - indexedNums[i - 1].first <= limit) {
                pairs.push_back({indexedNums[i - 1].second, indexedNums[i].second});
            }
        }

        DisjointSet ds(n);
        for (auto& pair: pairs)
            ds.unionOfNodes(pair.first, pair.second);

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            int root = ds.find(i);
            components[root].push_back(i);
        }

        for (auto& component: components) {
            vector<int> values;
            for (int index: component.second)
                values.push_back(nums[index]);

            sort(values.begin(), values.end());
            sort(component.second.begin(), component.second.end());

            for (int i = 0; i < component.second.size(); ++i)
                nums[component.second[i]] = values[i];
        }

        return nums;
    }
};
