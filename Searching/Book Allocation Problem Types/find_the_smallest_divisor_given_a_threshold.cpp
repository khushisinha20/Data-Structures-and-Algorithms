//leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int threshold, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += (ceil((double) nums[i]/ (double) mid));
            if (sum > threshold)
                return false;
        }
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (isPossible(nums, threshold, mid)) {
                res = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return res;
    }
};