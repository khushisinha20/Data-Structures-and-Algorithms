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
    int findPeakIndex(MountainArray& mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            int midPlusOneValue = mountainArr.get(mid + 1);

            if (midValue >= midPlusOneValue) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
    
    int binarySearchAscending(MountainArray& mountainArr, int& target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            
            if (midValue == target)
                return mid;
            else if (midValue < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return -1;
    }
    
    int binarySearchDescending(MountainArray& mountainArr, int& target, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            
            if (midValue == target)
                return mid;
            else if (midValue < target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeakIndex(mountainArr);
        
        int leftResult = binarySearchAscending(mountainArr, target, 0, peakIndex);
        
        if (leftResult != -1)
            return leftResult;
        
        int rightResult = binarySearchDescending(mountainArr, target, peakIndex + 1, mountainArr.length() - 1);
        return rightResult;
    }
};