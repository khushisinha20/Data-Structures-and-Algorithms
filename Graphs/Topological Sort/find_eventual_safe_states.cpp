//leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseGraph(vector<vector<int>>& graph, vector<vector<int>>& reversedGraph) {
        for (int vertex = 0; vertex < graph.size(); ++vertex) 
            for (auto adjacentVertex: graph[vertex]) 
                reversedGraph[adjacentVertex].push_back(vertex);
    }
    
    void findIndegrees(vector<int>& indegree, vector<vector<int>>& reversedGraph) {
        for (auto vertex = 0; vertex < reversedGraph.size(); ++vertex) {
            for (auto adjacentVertex: reversedGraph[vertex])
                ++indegree[adjacentVertex];
        }
    }
    
    void storeVerticesHavingZeroIndegree(vector<int>& indegree, queue<int>& zeroIndegreeVertices) {
        for (int vertex = 0; vertex < indegree.size(); ++vertex) {
            if (indegree[vertex] == 0)
                zeroIndegreeVertices.push(vertex);
        }
    }
    
    void bfs(vector<int>& indegree, queue<int>& zeroIndegreeVertices, vector<vector<int>>& reversedGraph, vector<int>& safeNodes) {
        while (!zeroIndegreeVertices.empty()) {
            int currentVertex = zeroIndegreeVertices.front();
            zeroIndegreeVertices.pop();
            safeNodes.push_back(currentVertex);
            for (auto adjacentVertex: reversedGraph[currentVertex]) {
                --indegree[adjacentVertex];
                if (indegree[adjacentVertex] == 0)
                    zeroIndegreeVertices.push(adjacentVertex);
            }
        }
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> reversedGraph(graph.size());
        reverseGraph(graph, reversedGraph);
        vector<int> indegree(graph.size(), 0);
        findIndegrees(indegree, reversedGraph);
        vector<int> safeNodes;
        queue<int> zeroIndegreeVertices;
        storeVerticesHavingZeroIndegree(indegree, zeroIndegreeVertices);
        bfs(indegree, zeroIndegreeVertices, reversedGraph, safeNodes);
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};