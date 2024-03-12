//leetcode.com/problems/evaluate-division/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> getGraph(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, vector<pair<string, double>>> graph;
        int n = equations.size(); 

        for (int i = 0; i < n; ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double value = values[i];
            graph[u].push_back({v, value});
            graph[v].push_back({u, 1 / value});
        }

        return graph;
    }

    void dfs(unordered_map<string, vector<pair<string, double>>>& graph, string& source, string& destination, unordered_set<string>& visited, double product, double& ans) {
        if (source == destination) {
            ans = product;
            return;
        }

        if (visited.find(source) != visited.end())
            return;

        visited.insert(source);

        for (auto& neighbor: graph[source]) {
            string node = neighbor.first;
            double value = neighbor.second;
            dfs(graph, node, destination, visited, product * value, ans);
        }
    } 

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph = getGraph(equations, values);
        vector<double> result;

        for (auto& query: queries) {
            string source = query[0];
            string destination = query[1];

            double ans = -1.0;
            double product = 1.0;

            if (graph.find(source) != graph.end()) {
                unordered_set<string> visited;
                dfs(graph, source, destination, visited, product, ans);
            }

            result.push_back(ans);
        }

        return result;
    }
};