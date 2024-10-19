//leetcode.com/problems/sum-of-subsequence-widths/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> power(n);
        power[0] = 1;

        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % MOD;

        long long ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            ans = (ans + power[i] * nums[i]) % MOD;
            ans = (ans - power[n - i - 1] * nums[i]) % MOD;
        }

        if (ans < 0) {
            ans += MOD;
        }

        return ans;
    }
};

