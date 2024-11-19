//leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long currentSum = 0;
        long long maxSum = 0;
        int start = 0;

        for (int end = 0; end < nums.size(); ++end) {
            int num = nums[end];
            currentSum += num;
            freq[num]++;

            while (freq[num] > 1 or end - start + 1 > k) {
                --freq[nums[start]];
                currentSum -= nums[start];
                if (freq[nums[start]] == 0)
                    freq.erase(nums[start]);
                ++start;
            }

            if (end - start + 1 == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};

