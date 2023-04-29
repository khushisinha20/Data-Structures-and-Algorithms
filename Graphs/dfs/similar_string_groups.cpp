//leetcode.com/problems/similar-string-groups/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSimilar(string& a, string& b) {
        int differences = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != b[i])
                ++differences;
        return differences == 2 or differences == 0;
    }

    unordered_map<string, vector<string>> getGraph(vector<string>& strs) {
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = i + 1; j < strs.size(); ++j) {
                if (isSimilar(strs[i], strs[j])) {
                    graph[strs[i]].push_back(strs[j]);
                    graph[strs[j]].push_back(strs[i]);
                }
            }
        }

        return graph;
    }

    void dfs(unordered_map<string, vector<string>>& graph, unordered_map<string, bool>& visited, string source) {
        visited[source] = true;

        for (auto neighbour: graph[source])
            if (!visited[neighbour])
                dfs(graph, visited, neighbour);
    }

    int numSimilarGroups(vector<string>& strs) {
        unordered_map<string, vector<string>> graph = getGraph(strs);
        unordered_map<string, bool> visited;
        int disconnectedComponents = 0;

        for (auto& str: strs) {
            if (!visited[str]) {
                ++disconnectedComponents;
                dfs(graph, visited, str);
            }
        }

        return disconnectedComponents;
    }
};
