//leetcode.com/problems/split-array-largest-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums, int m, int mid) {
        int splits = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > mid) {
                sum = nums[i];
                ++splits;
                if (splits > m)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleToSplit(nums, m, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
};