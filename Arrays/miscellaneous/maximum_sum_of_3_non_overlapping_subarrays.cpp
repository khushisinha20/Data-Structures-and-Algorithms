//leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1);

        int sum = 0;
        for (int i = 0; i < k; ++i)
            sum += nums[i];
        sums[0] = sum;

        for (int i = k; i < n; ++i) {
            sum += nums[i] - nums[i - k];
            sums[i - k + 1] = sum;
        }

        vector<int> leftMaxIndex(n - k + 1);
        int maxIndex = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            if (sums[i] > sums[maxIndex])
                maxIndex = i;
            leftMaxIndex[i] = maxIndex;
        }

        vector<int> rightMaxIndex(n - k + 1);
        maxIndex = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (sums[i] >= sums[maxIndex])
                maxIndex = i;
            rightMaxIndex[i] = maxIndex;
        }

        vector<int> result(3);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int left = leftMaxIndex[i - k];
            int right = rightMaxIndex[i + k];
            int total = sums[left] + sums[i] + sums[right];

            if (total > maxSum) {
                maxSum = total;
                result = {left, i, right};
            }
        }

        return result;
    }
};
