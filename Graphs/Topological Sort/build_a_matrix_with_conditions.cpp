//leetcode.com/problems/build-a-matrix-with-conditions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getGraph(vector<vector<int>>& conditions, int& k) {
        vector<vector<int>> graph(k + 1);
        for (auto& condition: conditions)
            graph[condition[0]].push_back(condition[1]);
        return graph;
    }
    
    vector<int> getIndegree(vector<vector<int>>& graph, int& k) {
        vector<int> indegree(k + 1, 0);
        for (int node = 1; node <= k; ++node) {
            for (auto& adjacentNode: graph[node])
                ++indegree[adjacentNode];
        }
        return indegree;
    }
    
    queue<int> getZeroIndegreeNodes(vector<int>& indegree) {
        queue<int> zeroIndegreeNodes;
        for (int node = 1; node < indegree.size(); ++node)
            if (indegree[node] == 0)
                zeroIndegreeNodes.push(node);
        return zeroIndegreeNodes;
    }
    
    vector<int> getPositions(vector<vector<int>>& graph, int& k) {
        vector<int> position(k + 1);
        int currentIndex = -1;
        
        vector<int> indegree = getIndegree(graph, k);
        queue<int> zeroIndegreeNodes = getZeroIndegreeNodes(indegree);
        
        while (!zeroIndegreeNodes.empty()) {
            int currentNode = zeroIndegreeNodes.front();
            zeroIndegreeNodes.pop();
            
            position[currentNode] = ++currentIndex;
            
            for (auto& adjacentNode: graph[currentNode]) {
                --indegree[adjacentNode];
                if (indegree[adjacentNode] == 0)
                    zeroIndegreeNodes.push(adjacentNode);
            }
        }
        
        if (currentIndex != k - 1)
            return {};
            
        return position;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph = getGraph(rowConditions, k);
        vector<vector<int>> colGraph = getGraph(colConditions, k);
        
        vector<int> rowWiseIndex = getPositions(rowGraph, k);
        vector<int> colWiseIndex = getPositions(colGraph, k);
        
        if (rowWiseIndex.empty() or colWiseIndex.empty())
            return {};
        
        vector<vector<int>> matrix(k, vector<int> (k, 0));
        
        for (int node = 1; node <= k; ++node) {
            int rowIndex = rowWiseIndex[node];
            int colIndex = colWiseIndex[node];
            matrix[rowIndex][colIndex] = node;
        }
        
        return matrix;
    }
};