//leetcode.com/problems/minimize-maximum-pair-sum-in-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int max_pair_sum = 0;
        int pair_sum = 0;
        sort(nums.begin(), nums.end());
        while (start < end) {
            pair_sum = nums[start] + nums[end];
            max_pair_sum = max(max_pair_sum, pair_sum);
            ++start;
            --end;
        }
        return max_pair_sum;
    }
};