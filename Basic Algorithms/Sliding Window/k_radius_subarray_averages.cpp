//leetcode.com/problems/k-radius-subarray-averages/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> averages(nums.size(), -1);
        int start = 0;
        long long sum = 0;
        for (int end = 0; end < nums.size(); ++end) {
            sum += nums[end];
            if (end - start + 1 == (2 * k + 1)) {
                int mid = (start + k);
                averages[mid] = (sum / (2 * k + 1));
                sum -= nums[start];
                ++start;
            }
        }
        return averages;
    }
};