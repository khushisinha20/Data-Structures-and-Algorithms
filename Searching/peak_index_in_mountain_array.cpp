//leetcode.com/problems/peak-index-in-a-mountain-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFirstElement(int mid) {
        return mid == 0;
    }
    
    bool isLastElement(int mid, vector<int>& arr) {
        return mid == arr.size() - 1;
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (!isFirstElement(mid) && !isLastElement(mid, arr)) {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) 
                    return mid;
                else if (arr[mid] < arr[mid + 1]) {
                    low = mid + 1;
                } else if (arr[mid] < arr[mid - 1]) {
                    high = mid - 1;
                }
            } else if (isFirstElement(mid))
                return 1;
            else
                return arr.size() - 2;
        }
        return -1;
    }
};