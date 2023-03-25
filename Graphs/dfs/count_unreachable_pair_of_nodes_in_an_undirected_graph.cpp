//leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<long long>> getGraph(int& n, vector<vector<int>>& edges) {
        vector<vector<long long>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    
    void dfs(int node, vector<bool>& visited, long long& clusters, vector<vector<long long>>& graph) {
        visited[node] = true;
        ++clusters;
        
        for (auto neighbour: graph[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited, clusters, graph);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<long long>> graph = getGraph(n, edges);
        vector<bool> visited(n, false);
        long long result = 0;
        
        long long clusters = 0;
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                clusters = 0;
                dfs(node, visited, clusters, graph);
                result += (n - clusters) * clusters;
            }
        }
        
        return result / 2;
    }
};