//leetcode.com/problems/most-profitable-path-in-a-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> tree;
    vector<int> distanceFromRoot;
    vector<int> parent; 
    vector<bool> visited;
    int maxNetIncome = INT_MIN;
    
    void constructTree(vector<vector<int>>& edges) {
        for (auto edge: edges) {
            tree[edge[1]].push_back(edge[0]);
            tree[edge[0]].push_back(edge[1]);
        }
    }
    
    void dfsToFindParent(int currentNode, int dist, int parentOfNode) {
        distanceFromRoot[currentNode] = dist;
        parent[currentNode] = parentOfNode;
        
        for (auto adjacentNode: tree[currentNode]) {
            if (adjacentNode == parentOfNode)
                continue;
            dfsToFindParent(adjacentNode, dist + 1, currentNode);
        }
    }
    
    void visitByBob(int& bob, vector<int>& amount) {
        int currentNode = bob;
        int distanceMovedByBob = 0;
        while (currentNode != 0) {
            if (distanceFromRoot[currentNode] > distanceMovedByBob)
                amount[currentNode] = 0;
            if (distanceFromRoot[currentNode] == distanceMovedByBob)
                amount[currentNode] /= 2;
            currentNode = parent[currentNode];
            ++distanceMovedByBob;
        }
    }
    
    void visitByAlice(vector<bool>& visited, int source, int& currentIncome, vector<int>& amount) {
        visited[source] = true;
        currentIncome += amount[source];
        int unvisitedNeighbours = 0;
        
        for (auto adjacentNode: tree[source]) {
            if (!visited[adjacentNode]) {
                ++unvisitedNeighbours;
                visitByAlice(visited, adjacentNode, currentIncome, amount);
            }
        }
        
        if (unvisitedNeighbours == 0)
            maxNetIncome = max(maxNetIncome, currentIncome);
        
        currentIncome -= amount[source];
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        constructTree(edges);
        distanceFromRoot.resize(edges.size() + 1, -1);
        parent.resize(edges.size() + 1, -1);
        dfsToFindParent(0, 0, 0);
        visitByBob(bob, amount);
        vector<bool> visited(edges.size(), false);
        int currentIncome = 0;
        visitByAlice(visited, 0, currentIncome, amount);
        return maxNetIncome;
    }
};