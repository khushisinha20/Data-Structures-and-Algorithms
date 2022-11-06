#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void createAdjacencyList(vector<vector<int>>& edges, int n, vector<vector<pair<int, int>>>& adjacencyList) {
        for (auto edge: edges) {
            adjacencyList[edge[0]].push_back({edge[1], edge[2]});
            adjacencyList[edge[1]].push_back({edge[0], edge[2]});
        }
    }
    
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adjacencyList(n + 1);
        createAdjacencyList(edges, n, adjacencyList);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> parent(n + 1);
        parent[1] = 1;
        vector<int> distance(n + 1, INT_MAX);
        distance[1] = 0;
        minHeap.push({0, 1});
        
        while (!minHeap.empty()) {
            int currentNode = minHeap.top().second;
            int currentDistance = minHeap.top().first;
            minHeap.pop();
            
            for (auto neighbour: adjacencyList[currentNode]) {
                int adjacentNode = neighbour.first;
                int edgeWeight = neighbour.second;
                if (currentDistance + edgeWeight < distance[adjacentNode]) {
                    distance[adjacentNode] = currentDistance + edgeWeight;
                    minHeap.push({currentDistance + edgeWeight, adjacentNode});
                    parent[adjacentNode] = currentNode;
                }
            }
        }
        
        if (distance[n] == INT_MAX)
            return {-1};
            
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};