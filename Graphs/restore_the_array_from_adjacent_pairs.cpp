//leetcode.com/problems/restore-the-array-from-adjacent-pairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> getGraph(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        for (auto& pair: pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        return graph;
    }
    
    void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, vector<int>& result, int node) {
        visited.insert(node);
        result.push_back(node);
        
        for (auto& adjacentNode: graph[node]) {
            if (visited.find(adjacentNode) == visited.end())
                dfs(graph, visited, result, adjacentNode); // Corrected the recursive call
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        auto graph = getGraph(adjacentPairs);
        unordered_set<int> visited;
        
        // Find the start node (a node with only one adjacent node)
        int start = -1;
        for (auto& entry: graph) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }
        
        vector<int> result;
        dfs(graph, visited, result, start);
        return result;
    }
};
