//leetcode.com/problems/find-in-mountain-array/

#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
    public:
      int get(int index);
      int length();
};

class Solution {
public:
    int findMaximum(MountainArray& mountainArr) {
        int low = 0;
        int n = mountainArr.length();
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_element = mountainArr.get(mid);
            if (mid > 0 && mid < n - 1) {
                if (mid_element > mountainArr.get(mid - 1) && mid_element > mountainArr.get(mid + 1))
                    return mid;
                else if (mid_element < mountainArr.get(mid - 1))
                    high = mid - 1;
                else 
                    low = mid + 1;
            } else if (mid == 0) {
                if (mid_element > mountainArr.get(mid + 1))
                    return 0;
                return 1;
            } else {
                if (mid_element > mountainArr.get(n - 2))
                    return n - 1;
                return n - 2;
            }
        }
        return -1;
    }
    
    int findBeforeMaximum(MountainArray& mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_element = mountainArr.get(mid);
            if (mid_element == target)
                return mid;
            else if (mid_element < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        return INT_MAX;
    }
    
    int findAfterMaximum(MountainArray& mountainArr, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int mid_element = mountainArr.get(mid);
            if (mid_element == target)
                return mid;
            else if (mid_element < target)
                high = mid - 1;
            else 
                low = mid + 1;
        }
        return INT_MAX;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int maxInMountainArray = findMaximum(mountainArr);
        int n = mountainArr.length();
        int occurenceBeforeMaximum = findBeforeMaximum(mountainArr, target, 0, maxInMountainArray - 1);
        int occurenceAfterMaximum = findAfterMaximum(mountainArr, target, maxInMountainArray, n - 1);
        int res = min(occurenceBeforeMaximum, occurenceAfterMaximum);
        return res == INT_MAX ? -1 : res;
    }
};
