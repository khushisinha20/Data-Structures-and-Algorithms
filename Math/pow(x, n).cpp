//leetcode.com/problems/powx-n/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long power = abs(n);
        double ans = 1.0;
        
        while (power > 0) {
            if (power & 1) {
                ans *= x;
                --power;
            } else {
                x *= x;
                power /= 2;
            }
        }
        
        return n >= 0 ? ans : 1.0 / ans;
    }
};