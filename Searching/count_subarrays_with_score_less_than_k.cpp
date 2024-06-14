//leetcode.com/problems/count-subarrays-with-score-less-than-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        return prefixSum;
    }

    bool isScoreLessThanLimit(vector<long long>& prefixSum, int start, int end, long long k) {
        long long sum = prefixSum[end] - (start > 0 ? prefixSum[start - 1] : 0);
        long long length = end - start + 1;
        return sum * length < k;
    }

    long long subarrayStartingFromHere(vector<long long>& prefixSum, int start, long long k) {
        int high = prefixSum.size() - 1;
        int low = start;
        long long ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isScoreLessThanLimit(prefixSum, start, mid, k)) {
                ans = mid - start + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> prefixSum = getPrefixSum(nums);
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += subarrayStartingFromHere(prefixSum, i, k);
        }

        return ans;
    }
};

