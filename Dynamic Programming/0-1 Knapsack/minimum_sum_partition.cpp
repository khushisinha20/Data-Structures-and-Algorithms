//practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
    void subsetWithGivenSum(int arr[], int n, vector<vector<bool>>& dp, int range) {
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < range + 1; ++j) {
                if (j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else {
                    if (arr[i - 1] <= j)
                        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                    else 
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
  
    int findRange(int arr[], int n) {
        int range = 0;
        for (int i = 0; i < n; ++i)
            range += arr[i];
        return range;
    }
  
	int minDifference(int arr[], int n)  { 
	    int range = findRange(arr, n);
	    vector<vector<bool>> dp(n + 1, vector<bool> (range + 1, false));
	    subsetWithGivenSum(arr, n, dp, range);
	    
	    int minDiff = INT_MAX;
	    for (int i = 0; i <= range / 2; ++i) {
	        if (dp[n][i])
	            minDiff = min(minDiff, range - 2 * i);
	    }
	    return minDiff;
	} 
};