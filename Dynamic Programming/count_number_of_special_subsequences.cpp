//leetcode.com/problems/count-number-of-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        const int MOD = 1000000007;
        long long dp0 = 0;
        long long dp1 = 0;
        long long dp2 = 0;

        for (int num: nums) {
            if (num == 0) {
                dp0 = (2 * dp0 + 1) % MOD;
            } else if (num == 1) {
                dp1 = (dp0 + 2 * dp1) % MOD;
            } else {
                dp2 = (dp1 + 2 * dp2) % MOD;
            }
        }

        return dp2;
    }
};
