//leetcode.com/problems/unique-substrings-in-wraparound-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.length();
        vector<int> dp(26, 0);
        
        dp[s[0] - 'a'] = 1;
        int maxLength = 1;
        
        for (int i = 1; i < n; ++i) {
            if ((s[i] - s[i - 1] + 26) % 26 == 1)
                ++maxLength;
            else
                maxLength = 1;
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], maxLength);
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};