//practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int LongestRepeatingSubsequence(string str) {
	    vector<vector<int>> dp(str.length() + 1, vector<int> (str.length() + 1, -1));
	    
	    for (int i = 0; i <= str.length(); ++i) {
	        for (int j = 0; j <= str.length(); ++j) {
	            if (i == 0 || j == 0)
	                dp[i][j] = 0;
	            else if (i != j && str[i - 1] == str[j - 1])
	                dp[i][j] = 1 + dp[i - 1][j - 1];
	            else
	                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
	        }
	    }
	    return dp[str.length()][str.length()];
	}

};