//leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (x > sum)
            return -1;
        int target = sum - x;
        int start = 0;
        int current_sum = 0;
        int max_length = INT_MIN;
        for (int end = 0; end < nums.size(); ++end) {
            current_sum += nums[end];
            while (current_sum > target) {
                current_sum -= nums[start];
                ++start;
            }
            if (current_sum == target) {
                max_length = max(max_length, end - start + 1);
            }
        }
        if (max_length == INT_MIN)
            return -1;
        return nums.size() - max_length;
    }
};