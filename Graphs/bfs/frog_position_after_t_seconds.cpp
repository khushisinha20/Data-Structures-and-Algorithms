//leetcode.com/problems/frog-position-after-t-seconds/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& adjacencyList, vector<vector<int>>& edges) {
        for (auto edge: edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adjacencyList(n + 1);
        createAdjacencyList(adjacencyList, edges);
        
        queue<pair<pair<int, int>, double>> nodeProbability;
        vector<bool> visited(n + 1, false);
        
        nodeProbability.push({{1, t}, 1.0});
        visited[1] = true;
        
        while (!nodeProbability.empty()) {
            int node = nodeProbability.front().first.first;
            int time = nodeProbability.front().first.second;
            double probability = nodeProbability.front().second;
            
            int unvisitedNeighbours = 0;
            for (auto adjacentNode: adjacencyList[node])
                if (!visited[adjacentNode])
                    ++unvisitedNeighbours;
            
            if (node == target) {
                if (time == 0 || unvisitedNeighbours == 0)
                    return probability;
                return 0;
            }
            
            nodeProbability.pop();
            
            if (time > 0) {
                for (auto adjacentNode: adjacencyList[node]) {
                    if (!visited[adjacentNode]) {
                        visited[adjacentNode] = true;
                        if (unvisitedNeighbours != 0) 
                            nodeProbability.push({{adjacentNode, time - 1}, probability / unvisitedNeighbours});
                    }
                }
            }
        }
        return 0;
    }
};