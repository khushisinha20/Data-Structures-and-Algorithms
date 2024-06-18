//leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& counter, vector<bool>& visited, string& labels, vector<int>& result) {
        visited[node] = true;
        ++counter[node][labels[node] - 'a'];

        for (int neighbor: graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, counter, visited, labels, result);
                for (int i = 0; i < 26; ++i)
                    counter[node][i] += counter[neighbor][i];
            }
        }

        result[node] = counter[node][labels[node] - 'a'];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph = getGraph(n, edges);
        vector<int> result(n, 0);
        vector<vector<int>> counter(n, vector<int>(26, 0));
        vector<bool> visited(n, false);
        dfs(0, graph, counter, visited, labels, result);
        return result;
    }
};
