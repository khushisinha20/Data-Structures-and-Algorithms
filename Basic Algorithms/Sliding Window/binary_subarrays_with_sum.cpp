//leetcode.com/problems/binary-subarrays-with-sum/submissions/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int atmostSum(vector<int>& nums, int goal) {
        int start = 0;
        int res = 0;
        int sum = 0;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            while (start <= end && sum > goal) {
                sum -= nums[start];
                ++start;
            }
            res += (end - start + 1);
        }
        return res;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostSum(nums, goal) - atmostSum(nums, goal - 1);
    }
};