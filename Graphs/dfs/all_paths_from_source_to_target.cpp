//leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int> currentPath, vector<vector<int>>& paths) {
        currentPath.push_back(node);
        if (node == graph.size() - 1)
            paths.push_back(currentPath);
        else {
            for (auto adjacentNode: graph[node]) 
                dfs(adjacentNode, graph, currentPath, paths);
            currentPath.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> currentPath;
        dfs(0, graph, currentPath, paths);
        return paths;
    }
};