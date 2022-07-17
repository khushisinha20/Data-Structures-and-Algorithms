//leetcode.com/problems/kth-smallest-number-in-multiplication-table/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSmallerNumbers(int m, int n, int mid) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(mid / i, n);
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (countOfSmallerNumbers(m, n, mid) < k) 
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};