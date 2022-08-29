#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayGraph(vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        for (auto vertex: adj[i])
            cout << vertex << " ";
        cout << endl;
    }
}

int main() {
    int vertices = 4;
    vector<vector<int>> adj(vertices);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    displayGraph(adj);
    return 0;
}