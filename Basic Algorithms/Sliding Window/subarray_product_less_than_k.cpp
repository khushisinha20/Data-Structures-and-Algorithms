//leetcode.com/problems/subarray-product-less-than-k

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        int product = 1;
        int count_of_subarrays = 0;
        for (int end = 0; end < nums.size(); ++end) {
            product *= nums[end];
            while (start <= end && product >= k) {
                product /= nums[start];
                ++start;
            }
            if (product < k)
                count_of_subarrays += (end - start + 1);
        }
        return count_of_subarrays;
    }
};