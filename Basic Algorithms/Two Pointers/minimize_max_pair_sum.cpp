//leetcode.com/problems/minimize-maximum-pair-sum-in-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_pair_sum = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            max_pair_sum = max(max_pair_sum, (nums[i++] + nums[j--]));
        }
        return max_pair_sum;
    }
};