//leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "0");
        dp[0] = "";
        
        for (int t = 1; t <= target; ++t) {
            for (int i = 0; i < 9; ++i) {
                if (t >= cost[i] and dp[t - cost[i]] != "0") {
                    string candidate = to_string(i + 1) + dp[t - cost[i]];
                    if (dp[t].length() < candidate.length())
                        dp[t] = candidate;
                    else if (dp[t].length() == candidate.length())
                        dp[t] = max(dp[t], candidate);
                }
            }
        }
        
        return dp[target];
    }
};