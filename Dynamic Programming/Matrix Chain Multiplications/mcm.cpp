//practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int helper(int arr[], int low, int high, vector<vector<int>>& dp) {
        if (low >= high)
            return 0;
            
        if (dp[low][high] != -1)
            return dp[low][high];
            
            
        int minMultiplications = INT_MAX;
        for (int i = low; i < high; ++i) {
            int multiplications = helper(arr, low, i, dp) + helper(arr, i + 1, high, dp) + arr[low - 1] * arr[i] * arr[high];
            minMultiplications = min(minMultiplications, multiplications);
        }
        
        return dp[low][high] = minMultiplications;
    }

    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N + 1, vector<int> (N + 1, -1));
        return helper(arr, 1, N - 1, dp);
    }
};