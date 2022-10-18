//leetcode.com/problems/flower-planting-with-no-adjacent/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int source, vector<int>& color, vector<vector<int>>& adjacencyList) {
        queue<int> vertices;
        vertices.push(source);
        color[source] = 1;
        
        while (!vertices.empty()) {
            int currentVertex = vertices.front();
            vertices.pop();
            
            for (auto adjacentVertex: adjacencyList[currentVertex]) {
                if (color[adjacentVertex] == 0 || color[adjacentVertex] == color[currentVertex]) {
                    color[adjacentVertex] = color[currentVertex] + 1;
                    vertices.push(adjacentVertex);
                }
                if (color[adjacentVertex] > 4)
                    color[adjacentVertex] %= 4;
            }
        }
    }
    
    void createAdjacencyList(vector<vector<int>>& paths, vector<vector<int>>& adjacencyList) {
        for (auto path: paths) {
            adjacencyList[path[0] - 1].push_back(path[1] - 1);
            adjacencyList[path[1] - 1].push_back(path[0] - 1);
        }
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjacencyList(n + 1);
        createAdjacencyList(paths, adjacencyList);
        vector<int> colors(n, 0);
        for (int vertex = 0; vertex <= n - 1; ++vertex) {
            if (!colors[vertex])
                bfs(vertex, colors, adjacencyList);
        }
        return colors;
    }
};