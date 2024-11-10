//leetcode.com/problems/painting-a-grid-with-three-different-colors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    void generateAllColorStates(vector<string>& states, string state, char previous, int col) {
        if (col == 0) {
            states.push_back(state);
            return;
        }

        string colors = "RGB";
        for (auto& color: colors) {
            if (color != previous) {
                generateAllColorStates(states, state + color, color, col - 1);
            }
        }
    }

    vector<vector<int>> createGraph(vector<string>& states, int& m) {
        int numStates = states.size();

        vector<vector<int>> graph(numStates);
        for (int i = 0; i < numStates; ++i) {
            for (int j = 0; j < numStates; ++j) {
                bool isCompatible = true;
                for (int k = 0; k < m; ++k) {
                    if (states[i][k] == states[j][k]) {
                        isCompatible = false;
                        break;
                    }
                }

                if (isCompatible)
                    graph[i].push_back(j);
            }
        }

        return graph;
    }

    long long waysToFill(vector<vector<int>>& dp, int currentState, int colsToFill, vector<vector<int>>& graph) {
        if (colsToFill == 0)
            return 1;

        if (dp[currentState][colsToFill] != -1)
            return dp[currentState][colsToFill];

        long long ways = 0;
        for (auto& nextState: graph[currentState]) {
            ways = (ways + waysToFill(dp, nextState, colsToFill - 1, graph)) % MOD;
        }

        return dp[currentState][colsToFill] = ways;
    }

    int colorTheGrid(int m, int n) {
        vector<string> states;
        string state;
        char previous = '*';
        generateAllColorStates(states, state, previous, m);

        vector<vector<int>> graph = createGraph(states, m);
        int numStates = states.size();

        vector<vector<int>> dp(numStates, vector<int> (n + 1, -1));

        int totalWays = 0;
        for (int i = 0; i < numStates; ++i) {
            totalWays = (totalWays + waysToFill(dp, i, n - 1, graph)) % MOD;
        }

        return totalWays;
    }
};

