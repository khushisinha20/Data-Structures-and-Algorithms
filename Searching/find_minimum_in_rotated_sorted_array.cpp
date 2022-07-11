//leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMinimum(int mid, vector<int>& nums) {
        int n = nums.size();
        int previous = (mid - 1 + n) % n;
        int next = (mid + 1) % n;
        return (nums[previous] >= nums[mid]) && (nums[next] >= nums[mid]);
    }
    
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            if (nums[low] <= nums[high])
                return nums[low];
            int mid = low + (high - low) / 2;
            if (isMinimum(mid, nums)) 
                return nums[mid];
            else if (nums[low] <= nums[mid]) 
                low = mid + 1;
            else if (nums[mid] <= nums[high])
                high = mid - 1;
        }
        return -1;
    }
};