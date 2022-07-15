//leetcode.com/problems/sqrtx/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }
};