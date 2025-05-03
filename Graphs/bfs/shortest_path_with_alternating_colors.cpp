//leetcode.com/problems/shortest-path-with-alternating-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<int>>> createGraph(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n);

        for (auto& edge : redEdges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v, 0});
        }

        for (auto& edge : blueEdges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back({v, 1});
        }

        return graph;
    }

    int bfs(int target, vector<vector<vector<int>>>& graph, int& n) {
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<tuple<int, int, int>> state;
        state.push({0, 0, -1});

        while (!state.empty()) {
            auto [currentNode, distance, color] = state.front();
            state.pop();

            if (currentNode == target)
                return distance;

            for (auto& neighbor : graph[currentNode]) {
                int adjNode = neighbor[0];
                int edgeColor = neighbor[1];

                if (edgeColor != color && !visited[adjNode][edgeColor]) {
                    visited[adjNode][edgeColor] = true;
                    state.push({adjNode, distance + 1, edgeColor});
                }
            }
        }

        return -1;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph = createGraph(n, redEdges, blueEdges);
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            result[i] = bfs(i, graph, n);
        }

        return result;
    }
};

