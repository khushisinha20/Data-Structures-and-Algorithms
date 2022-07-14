//practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
    bool isValid(int a[], int n, int k, int mid) {
        int students = 1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (sum > mid) {
                sum = a[i];
                ++students;
                if (students > k)
                    return false;
            }
        }
        return true;
    }
    
    int findPages(int a[], int n, int k) {
        if (n < k)
            return -1;
        int sum = 0;
        int max_element = 0;
        for (int i = 0; i < n; ++i) {
            max_element = max(max_element, a[i]);
            sum += a[i];
        }
        int low = max_element;
        int high = sum;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(a, n, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }                
        }
        return res;
    }
};