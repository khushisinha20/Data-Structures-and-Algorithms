//leetcode.com/problems/shortest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> createGraph(int& n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    void bfs(int source, vector<vector<int>>& graph, int& shortestCycle) {
        int n = graph.size();
        vector<int> distance(n, -1);
        vector<int> parent(n, -1);

        queue<int> nodes;
        distance[source] = 0;
        nodes.push(source);

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int neighbor: graph[node]) {
                if (distance[neighbor] == -1) {
                    distance[neighbor] = distance[node] + 1;
                    parent[neighbor] = node;
                    nodes.push(neighbor);
                } else if (parent[node] != neighbor) {
                    shortestCycle = min(shortestCycle, distance[node] + distance[neighbor] + 1);
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph = createGraph(n, edges);
        int shortestCycle = INT_MAX;

        for (int start = 0; start < n; ++start) {
            bfs(start, graph, shortestCycle);
        }

        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};
