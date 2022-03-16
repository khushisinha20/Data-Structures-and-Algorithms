//leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0;
        int zeroes = 0;
        int ones = 0; 
        int longest_subarray_of_1s = 0;
        for (int end = 0; end < nums.size(); ++end) {
            if (nums[end] == 0)
                ++zeroes;
            while (zeroes > 1 && start <= end) {
                if (nums[start] == 0)
                    --zeroes;
                ++start;
            }
            longest_subarray_of_1s = max(longest_subarray_of_1s, end - start + 1 - zeroes);
        }
        if (longest_subarray_of_1s == nums.size())
            return --longest_subarray_of_1s;
        return longest_subarray_of_1s;
    }
};