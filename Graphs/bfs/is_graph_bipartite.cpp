//leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int& source, vector<vector<int>>& graph, vector<int>& colors, int& total_vertices) {
        queue<int> vertices;
        vertices.push(source);
        colors[source] = 0;
        
        while (!vertices.empty()) {
            int vertex = vertices.front();;
            vertices.pop();
            for (auto adjacentVertex: graph[vertex]) {
                if (colors[adjacentVertex] == -1) {
                    colors[adjacentVertex] = !colors[vertex];
                    vertices.push(adjacentVertex);
                } else if (colors[adjacentVertex] == colors[vertex])
                    return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int total_vertices = graph.size();
        vector<int> colors(total_vertices, -1);
        for (int vertex = 0; vertex < total_vertices; ++vertex) 
            if (colors[vertex] == -1) 
                if (!bfs(vertex, graph, colors, total_vertices))
                    return false;
        
        return true;
    }
};