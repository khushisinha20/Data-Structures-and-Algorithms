//leetcode.com/problems/missing-number/

#include <bits/std++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        if (nums.size() == 1 and nums[0] == 0)
            return 1;
        
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] != mid) { 
                if (mid > 0 and nums[mid - 1] == mid - 1)
                    return mid;
                high = mid - 1;
            } else if (nums[mid] == mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return mid == nums.size() ? nums.size() : 0;
    }
};