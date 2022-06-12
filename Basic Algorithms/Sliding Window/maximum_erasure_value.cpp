//leetcode.com/problems/maximum-erasure-value/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> distinct_elements;
        int start = 0;
        int sum = 0;
        int max_sum = INT_MIN;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (distinct_elements.find(nums[end]) != distinct_elements.end()) {
                distinct_elements.erase(nums[start]);
                sum -= nums[start];
                ++start;
            }
            max_sum = max(max_sum, sum);
            distinct_elements.insert(nums[end]);
        }
        return max_sum;
    }
};