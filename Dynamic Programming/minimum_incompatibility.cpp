//leetcode.com/problems/minimum-incompatibility/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(unordered_map<int, int>& memo, vector<int>& nums, vector<vector<pair<int, int>>>& validGroups, int mask, int& n, int& k, int& subsetSize) {
        if (mask == (1 << n) - 1)
            return 0;

        if (memo.count(mask))
            return memo[mask];

        int used = __builtin_popcount(mask);
        if (used % subsetSize != 0)
            return 1e9;

        int result = 1e9;

        for (auto& [groupMask, incompatibility] : validGroups[mask]) {
            int newMask = mask | groupMask;
            result = min(result, dfs(memo, nums, validGroups, newMask, n, k, subsetSize) + incompatibility);
        }

        return memo[mask] = result;
    }

    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int subsetSize = n / k;

        vector<vector<pair<int, int>>> validGroups(1 << n);
        unordered_map<int, int> memo;

        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) != subsetSize)
                continue;

            unordered_set<int> seen;
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            bool valid = true;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (seen.count(nums[i])) {
                        valid = false;
                        break;
                    }
                    seen.insert(nums[i]);
                    minVal = min(minVal, nums[i]);
                    maxVal = max(maxVal, nums[i]);
                }
            }

            if (valid) {
                for (int prevMask = 0; prevMask < (1 << n); ++prevMask) {
                    if (!(prevMask & mask)) {
                        validGroups[prevMask].push_back({mask, maxVal - minVal});
                    }
                }
            }
        }

        int ans = dfs(memo, nums, validGroups, 0, n, k, subsetSize);
        return ans >= 1e9 ? -1 : ans;
    }
};
