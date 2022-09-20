//leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void createGraph(vector<vector<int>>& graph, vector<vector<int>>& edges) {
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    
    void findIndegrees(vector<int>& indegree, vector<vector<int>>& edges) {
        for (auto& edge: edges) {
            ++indegree[edge[0]];
            ++indegree[edge[1]];
        }
    }
    
    void storeNodesHavingIndegreeOne(queue<int>& oneIndegreeNodes, vector<int>& indegree) {
        for (int vertex = 0; vertex < indegree.size(); ++vertex)
            if (indegree[vertex] == 1)
                oneIndegreeNodes.push(vertex);
    }
    
    void bfs(vector<int>& indegree, queue<int>& oneIndegreeNodes, vector<vector<int>>& graph) {
        int nodesLeft = graph.size();
        while (nodesLeft > 2) {
            int totalOneIndegreeNodesCurrently = oneIndegreeNodes.size();
            nodesLeft -= totalOneIndegreeNodesCurrently;
            while (totalOneIndegreeNodesCurrently--) {
                int currentNode = oneIndegreeNodes.front();
                oneIndegreeNodes.pop();
                
                for (auto adjacentNode: graph[currentNode]) {
                    --indegree[adjacentNode];
                    if (indegree[adjacentNode] == 1)
                        oneIndegreeNodes.push(adjacentNode);
                }
            }
        }
    }
    
    void findRootsOfMHT(queue<int>& oneIndegreeNodes, vector<int>& rootsOfMHT) {
        while (!oneIndegreeNodes.empty()) {
            rootsOfMHT.push_back(oneIndegreeNodes.front());
            oneIndegreeNodes.pop();
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        
        vector<vector<int>> graph(n);
        createGraph(graph, edges);
        vector<int> indegree(n, 0);
        findIndegrees(indegree, edges);
        queue<int> oneIndegreeNodes;
        storeNodesHavingIndegreeOne(oneIndegreeNodes, indegree);
        bfs(indegree, oneIndegreeNodes, graph);
        vector<int> rootsOfMHT;
        findRootsOfMHT(oneIndegreeNodes, rootsOfMHT);
        return rootsOfMHT;
    }
};