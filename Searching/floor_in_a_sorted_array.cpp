//practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int findFloor(vector<long long> arr, long long n, long long target){
        int low = 0;
        int high = n - 1;
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] > target)
                high = mid - 1;
            else {
                if (res == -1 || arr[mid] > arr[res])
                    res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
};
