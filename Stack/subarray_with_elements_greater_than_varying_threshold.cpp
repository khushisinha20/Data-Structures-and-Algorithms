//leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nearestGreaterToLeft(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> left;

        for (int i = 0; i < n; ++i) {
            while (!left.empty() and nums[i] <= nums[left.top()])
                left.pop();
            if (!left.empty())
                result[i] = left.top();
            else
                result[i] = -1;
            left.push(i);
        }

        return result;
    }

    vector<int> nearestGreaterToRight(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> right;

        for (int i = n - 1; i >= 0; --i) {
            while (!right.empty() and nums[i] <= nums[right.top()])
                right.pop();
            if (!right.empty())
                result[i] = right.top();
            else
                result[i] = n;
            right.push(i);
        }

        return result;
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> ngl = nearestGreaterToLeft(nums);
        vector<int> ngr = nearestGreaterToRight(nums);

        for (int i = 0; i < n; ++i) {
            int k = ngr[i] - ngl[i] - 1;
            double limit = (double)threshold / (double)k;
            if (nums[i] > limit)
                return k;
        }

        return -1;
    }
};
