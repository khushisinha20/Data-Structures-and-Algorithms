//leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTotalScore(int startVertex, int endVertex, vector<int>& values, vector<vector<int>>& dp) {
        if (endVertex - startVertex < 2)
            return 0;
        
        if (dp[startVertex][endVertex] != -1)
            return dp[startVertex][endVertex];
        
        int minScore = INT_MAX;
        
        for (int cutVertex = startVertex + 1; cutVertex < endVertex; ++cutVertex) {
            int currentScore = values[startVertex] * values[cutVertex] * values[endVertex] + minTotalScore(startVertex, cutVertex, values, dp) + minTotalScore(cutVertex, endVertex, values, dp);
            minScore = min(minScore, currentScore);
        }
        
        return dp[startVertex][endVertex] = minScore;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int numVertices = values.size();
        vector<vector<int>> dp(numVertices, vector<int> (numVertices, -1));
        return minTotalScore(0, numVertices - 1, values, dp);
    }
};