//leetcode.com/problems/path-with-maximum-probability/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<pair<int, double>>> getGraph(vector<vector<int>>& edges, vector<double>& succProb, int& n) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return graph;
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> probability(n, 0);
        auto graph = getGraph(edges, succProb, n);
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start});
        probability[start] = 1;
        
        while (!maxHeap.empty()) {
            double currentProbability = maxHeap.top().first;
            int currentNode = maxHeap.top().second;
            maxHeap.pop();
            
            if (currentNode == end)
                return currentProbability;
            
            for (auto& neighbour: graph[currentNode]) {
                double edgeWeight = neighbour.second * currentProbability;
                int node = neighbour.first;
                if (edgeWeight > probability[node]) {
                    maxHeap.push({edgeWeight, node});
                    probability[node] = edgeWeight;
                }
            }
        }
        
        return 0;
    }
};