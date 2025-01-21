//leetcode.com/problems/cat-and-mouse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int mouse, int cat, int turn, int totalTurns, vector<vector<int>>& graph, vector<vector<vector<vector<int>>>>& dp) {
        if (totalTurns > 3 * graph.size())
            return 0;

        if (mouse == 0)
            return 1;

        if (mouse == cat)
            return 2;

        if (dp[mouse][cat][turn][totalTurns] != -1)
            return dp[mouse][cat][turn][totalTurns];

        if (turn == 0) {
            bool allCatWins = true;
            for (int next : graph[mouse]) {
                int result = helper(next, cat, 1, totalTurns, graph, dp);
                if (result == 1)
                    return dp[mouse][cat][turn][totalTurns] = 1;
                if (result != 2)
                    allCatWins = false;
            }
            return dp[mouse][cat][turn][totalTurns] = (allCatWins ? 2 : 0);
        } else {
            bool allMouseWins = true;
            for (int next : graph[cat]) {
                if (next == 0)
                    continue;
                int result = helper(mouse, next, 0, totalTurns + 1, graph, dp);
                if (result == 2)
                    return dp[mouse][cat][turn][totalTurns] = 2;
                if (result != 1)
                    allMouseWins = false;
            }
            return dp[mouse][cat][turn][totalTurns] = (allMouseWins ? 1 : 0);
        }
    }

    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(2, vector<int>(3 * n + 1, -1))));
        return helper(1, 2, 0, 0, graph, dp);
    }
};
