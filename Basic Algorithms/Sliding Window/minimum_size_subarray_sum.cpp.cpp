//leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
#include <vector>;
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int min_subarray_length = INT_MAX;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (sum >= target) {
                min_subarray_length = min(min_subarray_length, end - start + 1);
                sum -= nums[start];
                ++start;
            }
        }
        return min_subarray_length == INT_MAX? 0: min_subarray_length;
    }
};