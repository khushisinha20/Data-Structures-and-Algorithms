//leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;
            int currentCount = 0;
            for (int j = i; j < n; ++j) {
                if (!seen.count(nums[j])) {
                    if (seen.count(nums[j] + 1) and seen.count(nums[j] - 1))
                        --currentCount;
                    else if (!seen.empty() and !seen.count(nums[j] - 1) and !seen.count(nums[j] + 1))
                        ++currentCount;
                }
                seen.insert(nums[j]);
                ans += currentCount;
            }
        }

        return ans;
    }
};
