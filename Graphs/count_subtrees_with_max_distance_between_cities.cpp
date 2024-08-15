//leetcode.com/problems/count-subtrees-with-max-distance-between-cities/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getDistancesUsingFloydWarshall(int& n, vector<vector<int>>& edges) {
        vector<vector<int>> distance(n + 1, vector<int>(n + 1, INT_MAX));
        for (auto& edge : edges) {
            distance[edge[0]][edge[1]] = 1;
            distance[edge[1]][edge[0]] = 1;
        }

        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (i == j)
                        distance[i][j] = 0;
                    else if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }

        return distance;
    }

    vector<vector<int>> getGraph(int& n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }

    vector<set<int>> generateAllSubsets(int& n) {
        vector<set<int>> subsets;

        for (int i = 0; i < (1 << n); ++i) {
            set<int> currentSubset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentSubset.insert(j + 1);
                }
            }
            subsets.push_back(currentSubset);
        }

        return subsets;
    }

    void dfs(int node, int parent, const set<int>& nodes, vector<int>& visited, vector<vector<int>>& graph) {
        visited[node] = 1;
        for (int neighbor : graph[node]) {
            if (neighbor != parent && nodes.count(neighbor) && visited[neighbor] == 0) {
                dfs(neighbor, node, nodes, visited, graph);
            }
        }
    }

    bool isValidSubtree(int n, const set<int>& nodes, vector<vector<int>>& graph) {
        vector<int> visited(n + 1, 0);
        int startNode = *nodes.begin();
        dfs(startNode, -1, nodes, visited, graph);

        for (int node : nodes) {
            if (visited[node] == 0) return false;
        }
        return true;
    }

    int getMaxDistance(const vector<vector<int>>& distances, const set<int>& nodes) {
        int maxDist = 0;
        for (int u : nodes) {
            for (int v : nodes) {
                maxDist = max(maxDist, distances[u][v]);
            }
        }
        return maxDist;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> result(n - 1);
        vector<vector<int>> graph = getGraph(n, edges);
        vector<vector<int>> distances = getDistancesUsingFloydWarshall(n, edges);
        vector<set<int>> allSubsets = generateAllSubsets(n);

        for (auto& subset : allSubsets) {
            if (subset.size() > 1 && isValidSubtree(n, subset, graph)) {
                int diameter = getMaxDistance(distances, subset);
                if (diameter > 0 && diameter < n) {
                    result[diameter - 1]++;
                }
            }
        }

        return result;
    }
};
