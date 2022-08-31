//leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& edges, vector<vector<int>>& adjacencyList) {
        for (auto edge: edges) {
            int firstVertex = edge[0];
            int secondVertex = edge[1];
            adjacencyList[firstVertex].push_back(secondVertex);
            adjacencyList[secondVertex].push_back(firstVertex);
        }
    }
    
    bool bfs(vector<vector<int>>& adjacencyList, int& source, int& destination, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            int frontVertex = q.front();
            q.pop();
            if (frontVertex == destination)
                return true;
            for (auto vertex: adjacencyList[frontVertex]) {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacencyList(n);
        createAdjacencyList(edges, adjacencyList);
        vector<bool> visited(n, false);
        return bfs(adjacencyList, source, destination, visited);
    }
};