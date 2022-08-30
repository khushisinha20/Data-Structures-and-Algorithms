//leetcode.com/problems/number-of-provinces/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fillAdjacencyList(vector<vector<int>>& adjacencyList, vector<vector<int>>& isConnected) {
        for (int row = 0; row < isConnected.size(); ++row) {
            for (int col = 0; col < isConnected[0].size(); ++col) {
                if (isConnected[row][col]) {
                    adjacencyList[row].push_back(col);
                    adjacencyList[col].push_back(row);
                }
            }
        }
    }
    
    void bfsOnSingleComponent(int& source, vector<vector<int>>& adjacencyList, vector<bool>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            int frontVertex = q.front();
            q.pop();
            for (auto connectedEdges: adjacencyList[frontVertex]) {
                if (!visited[connectedEdges]) {
                    visited[connectedEdges] = true;
                    q.push(connectedEdges);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        vector<vector<int>> adjacencyList(vertices);
        fillAdjacencyList(adjacencyList, isConnected);
        int provinces = 0;
        vector<bool> visited(vertices, false);
        for (int vertex = 0; vertex < adjacencyList.size(); ++vertex) {
            if (!visited[vertex]) {
                ++provinces;
                bfsOnSingleComponent(vertex, adjacencyList, visited);
            }
        }
        return provinces;
    }
};