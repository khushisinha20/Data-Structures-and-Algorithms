//leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int source, vector<vector<int>>& graph, vector<int>& colors, int color) {
        colors[source] = color;
        
        for (auto adjacentVertex: graph[source]) {
            if (colors[adjacentVertex] == -1) {
                if (!dfs(adjacentVertex, graph, colors, !color))
                    return false; 
            } else if (colors[adjacentVertex] == color)
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int total_vertices = graph.size();
        vector<int> colors(total_vertices, -1);
        int source_color = 0;
        for (int vertex = 0; vertex < total_vertices; ++vertex) 
            if (colors[vertex] == -1) 
                if (!dfs(vertex, graph, colors, source_color))
                    return false;
        
        return true;
    }
};