//leetcode.com/problems/soup-servings/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<double>> dp;
    vector<pair<int, int>> serves = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    
    double helper(double A, double B) {
        if (A <= 0 and B <= 0)
            return 0.5;
        
        if (A <= 0)
            return 1.0;
        
        if (B <= 0)
            return 0.0;
        
        if (dp[A][B] != -1.0)
            return dp[A][B];
        
        double probability = 0.0;
        
        for (auto& serve: serves) {
            double serveOfA = serve.first;
            double serveOfB = serve.second;
            probability += 0.25 * helper(A - serveOfA, B - serveOfB);
        }
        
        return dp[A][B] = probability;
    }
    
    double soupServings(int n) {
        if (n >= 5000)
            return 1.0;
        
        dp.resize(n + 1, vector<double> (n + 1, -1.0));
        return helper(n, n);
    }
};