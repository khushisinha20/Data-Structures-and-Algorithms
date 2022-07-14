//practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(int arr[], int n, int k, long long mid) {
        long long painters = 1;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            if (sum > mid) {
                sum = arr[i];
                ++painters;
                if (painters > k)
                    return false;
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k) {
        long long sum = 0;
        int max_element = 0;
        for (int i = 0; i < n; ++i) {
            max_element = max(max_element, arr[i]);
            sum += arr[i];
        }
        long long low = max_element;
        long long high = sum;
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(arr, n, k, mid)) {
                res = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return res;
    }
};