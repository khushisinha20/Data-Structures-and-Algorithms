//leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;
    int dp[51][51][101];
    int N;
    int M;
    int K;
    
    int helper(int index, int searchCost, int maxSoFar) {
        if (index == N)
            return searchCost == K;
        
        if (dp[index][searchCost][maxSoFar] != -1)
            return dp[index][searchCost][maxSoFar];
        
        int result = 0;
        
        for (int i = 1; i <= M; ++i) {
            if (i > maxSoFar)
                result = (result + helper(index + 1, searchCost + 1, i)) % MOD;
            else
                result = (result + helper(index + 1, searchCost, maxSoFar)) % MOD;
        }
        
        return dp[index][searchCost][maxSoFar] = result;
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof dp);
        return helper(0, 0, 0);
    }
};