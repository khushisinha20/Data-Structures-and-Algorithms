//leetcode.com/problems/count-the-number-of-complete-components/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int source, int& nodeCount, int& edgeCount, vector<bool>& visited) {
        visited[source] = true;
        ++nodeCount;
        edgeCount += graph[source].size();

        for (auto adjacentNode: graph[source]) {
            if (!visited[adjacentNode]) {
                dfs(graph, adjacentNode, nodeCount, edgeCount, visited);
            }
        }
    }

    vector<vector<int>> getGraph(vector<vector<int>>& edges, int& n) {
        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = getGraph(edges, n);
        vector<bool> visited(n, false);
        int connectedComponents;

        for (int node = 0; node < n; ++node) {
            int nodeCount = 0;
            int edgeCount = 0;
            if (!visited[node]) {
                dfs(graph, node, nodeCount, edgeCount, visited);
                connectedComponents += (nodeCount * (nodeCount - 1) == edgeCount);
            }
        }

        return connectedComponents;
    }
};
