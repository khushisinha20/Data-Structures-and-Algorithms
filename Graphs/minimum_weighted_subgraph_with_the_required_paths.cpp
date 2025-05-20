//leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, int>>> createGraph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].push_back({to, weight});
        }
        return graph;
    }

    vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
        int n = graph.size();
        vector<long long> distance(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        minHeap.push({0, source});
        distance[source] = 0;

        while (!minHeap.empty()) {
            auto [currDist, currentNode] = minHeap.top();
            minHeap.pop();

            if (currDist > distance[currentNode]) continue;

            for (auto& neighbor : graph[currentNode]) {
                int adjacentNode = neighbor.first;
                int edgeWeight = neighbor.second;
                if (distance[currentNode] + edgeWeight < distance[adjacentNode]) {
                    distance[adjacentNode] = distance[currentNode] + edgeWeight;
                    minHeap.push({distance[adjacentNode], adjacentNode});
                }
            }
        }

        return distance;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph = createGraph(n, edges);

        vector<vector<pair<int, int>>> reverseGraph(n);
        for (auto& edge : edges) {
            reverseGraph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long long> src1Dist = dijkstra(graph, src1);
        vector<long long> src2Dist = dijkstra(graph, src2);
        vector<long long> destDist = dijkstra(reverseGraph, dest);

        long long ans = LLONG_MAX;
        for (int node = 0; node < n; ++node) {
            if (src1Dist[node] == LLONG_MAX || src2Dist[node] == LLONG_MAX || destDist[node] == LLONG_MAX)
                continue;
            ans = min(ans, src1Dist[node] + src2Dist[node] + destDist[node]);
        }

        return (ans == LLONG_MAX ? -1 : ans);
    }
};

