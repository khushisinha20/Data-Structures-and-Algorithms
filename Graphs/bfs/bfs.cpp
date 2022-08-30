#include <bits/stdc++.h>
using namespace std;

void createAdjacencyList(vector<set<int>>&adj, vector<pair<int, int>>& edges) {
    for (auto edge: edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfsOnSingleComponent(int source, vector<set<int>>& adj, vector<bool>& visited, vector<int>& bfs_traversal) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    
    while (!q.empty()) {
        int firstVertex = q.front();
        q.pop();
        bfs_traversal.push_back(firstVertex);
        for (auto i: adj[firstVertex]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<set<int>> adj(vertex);
    createAdjacencyList(adj, edges);
    vector<bool> visited(vertex, false);
    vector<int> bfs_traversal;
    for (int i = 0; i < vertex; ++i) {
        if (!visited[i])
            bfsOnSingleComponent(i, adj, visited, bfs_traversal);
    }
    return bfs_traversal;
}