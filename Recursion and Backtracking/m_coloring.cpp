//practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSafe(bool graph[101][101], int color, int vertex, vector<int>& colors, int n) {
        for (int i = 0; i < n; ++i) {
            if (graph[vertex][i] and colors[i] == color)
                return false;
        }

        return true;
    }

    bool graphColoringUtil(bool graph[101][101], int m, vector<int>& colors, int currentVertex, int& n) {
        if (currentVertex == n)
            return true;

        for (int color = 1; color <= m; ++color) {
            if (isSafe(graph, color, currentVertex, colors, n)) {
                colors[currentVertex] = color;

                if (graphColoringUtil(graph, m, colors, currentVertex + 1, n))
                    return true;

                colors[currentVertex] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> colors(101, 0);
        return (graphColoringUtil(graph, m, colors, 0, n));
    }
};
