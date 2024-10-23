//leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> createGraph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], 0});
            graph[edge[1]].push_back({edge[0], 1});
        }

        return graph;
    }

    int dfsToCalculateInitialReversals(vector<vector<pair<int, int>>>& graph, int node, int parent) {
        int totalReversals = 0;

        for (auto& [neighbor, isReverse] : graph[node]) {
            if (neighbor != parent) {
                totalReversals += isReverse;
                totalReversals += dfsToCalculateInitialReversals(graph, neighbor, node);
            }
        }

        return totalReversals;
    }

    void dfsToCalculateMinReversals(vector<vector<pair<int, int>>>& graph, vector<int>& ans, int node, int parent, int k) {
        ans[node] = k;

        for (auto& [neighbor, isReverse] : graph[node]) {
            if (neighbor != parent) {
                int newK = k;
                if (isReverse)
                    --newK;
                else
                    ++newK;

                dfsToCalculateMinReversals(graph, ans, neighbor, node, newK);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph = createGraph(n, edges);
        vector<int> ans(n);

        int k = dfsToCalculateInitialReversals(graph, 0, -1);
        dfsToCalculateMinReversals(graph, ans, 0, -1, k);

        return ans;
    }
};

