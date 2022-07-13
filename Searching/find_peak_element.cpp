//leetcode.com/problems/find-peak-element/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFirstElement(int mid) {
        return mid == 0;
    }
    
    bool isLastElement(int mid, vector<int>& nums) {
        return mid == nums.size() - 1;
    }
    
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!isFirstElement(mid) && !isLastElement(mid, nums)) {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                    return mid;
                else if (nums[mid] < nums[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else if (isFirstElement(mid)) {
                if (nums[0] > nums[1])
                    return 0;
                return 1;
            } else {
                if (nums.back() > nums[nums.size() - 2])
                    return nums.size() - 1;
                return nums.size() - 2;
            }
        }
        return -1;
    }
};