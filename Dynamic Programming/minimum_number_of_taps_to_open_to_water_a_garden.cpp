//leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int len = ranges.size();
        vector<int> dp(len, len + 1);
        dp[0] = 0;
        
        for (int i = 0; i < len; ++i) {
            int start = max(i - ranges[i], 0);
            int end = min(i + ranges[i], len - 1);
            for (int j = start; j <= end; ++j) {
                int openTap = dp[start] + 1;
                int closeTap = dp[j];
                dp[j] = min(openTap, closeTap);
            }
        }
        
        return dp[len - 1] >= len + 1 ? -1 : dp[len - 1];
    }
};
