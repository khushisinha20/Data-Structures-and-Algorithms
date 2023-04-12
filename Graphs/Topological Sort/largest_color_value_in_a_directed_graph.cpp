//leetcode.com/problems/largest-color-value-in-a-directed-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> getGraph(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge: edges) 
            graph[edge[0]].push_back(edge[1]);
        return graph;
    }
    
    vector<int> getIndegree(unordered_map<int, vector<int>>& graph, int& N) {
        vector<int> indegree(N, 0);
        for (auto& node: graph)
            for (auto& neighbour: graph[node.first])
                ++indegree[neighbour];
        return indegree;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int N = colors.size();
        unordered_map<int, vector<int>> graph = getGraph(edges);
        vector<int> indegree = getIndegree(graph, N);
        queue<int> nodes;
        vector<vector<int>> colorFrequency(N, vector<int> (26, 0));
        
        for (int node = 0; node < N; ++node) {
            if (indegree[node] == 0) {
                nodes.push(node);
                colorFrequency[node][colors[node] - 'a'] = 1;
            }
        }
        
        int result = 0;
        int visitedNodes = 0;
        
        while (!nodes.empty()) {
            int currentNode = nodes.front();
            nodes.pop();
            
            ++visitedNodes;
            result = max(colorFrequency[currentNode][colors[currentNode] - 'a'], result);
            
            for (auto& neighbour: graph[currentNode]) {
                for (int i = 0; i < 26; ++i) {
                    colorFrequency[neighbour][i] = max(colorFrequency[neighbour][i], colorFrequency[currentNode][i] + (colors[neighbour] - 'a' == i));
                }
                --indegree[neighbour];
                if (indegree[neighbour] == 0)
                    nodes.push(neighbour);
            }
        }
        
        return visitedNodes < N ? -1 : result;
    }
};