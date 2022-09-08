//leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int vertex, vector<bool>& visitedNode, vector<bool>& visitedPath, vector<vector<int>>& graph) {
        visitedNode[vertex] = true;
        visitedPath[vertex] = true;
        for (auto adjacentVertex: graph[vertex]) {
            if (!visitedNode[adjacentVertex]) {
                if (dfs(adjacentVertex, visitedNode, visitedPath, graph))
                    return true;
            } else if (visitedPath[adjacentVertex])
                    return true;
        }
        visitedPath[vertex] = false;
        return false;
    }
    
    void findSafeNodes(vector<bool>& visitedPath, vector<int>& safeNodes, int& total_vertices) {
        for (int vertex = 0; vertex < total_vertices; ++vertex)
            if (!visitedPath[vertex])
                safeNodes.push_back(vertex);
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int total_vertices = graph.size();
        vector<int> safeNodes;
        vector<bool> visitedNode(total_vertices, false);
        vector<bool> visitedPath(total_vertices, false);
        for (int vertex = 0; vertex < total_vertices; ++vertex) {
            if (!visitedNode[vertex]) 
                dfs(vertex, visitedNode, visitedPath, graph);
        }
        findSafeNodes(visitedPath, safeNodes, total_vertices);
        return safeNodes;
    }
};