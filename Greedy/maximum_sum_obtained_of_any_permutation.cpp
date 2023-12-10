//leetcode.com/problems/maximum-sum-obtained-of-any-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> frequency(n, 0);

        for (auto& request : requests) {
            int start = request[0];
            int end = request[1];
            ++frequency[start];
            if (end + 1 < n)
                --frequency[end + 1];
        }

        for (int i = 1; i < n; ++i)
            frequency[i] += frequency[i - 1];

        sort(nums.rbegin(), nums.rend());
        sort(frequency.rbegin(), frequency.rend());

        const int MOD = 1e9 + 7;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            result = (result % MOD + (static_cast<long long>(nums[i]) % MOD * frequency[i] % MOD) % MOD) % MOD;
        }

        return static_cast<int>(result);
    }
};
