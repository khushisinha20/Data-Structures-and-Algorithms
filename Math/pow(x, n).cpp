//leetcode.com/problems/powx-n/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) 
            x = (1 / x);
        n = abs(n);
        double product = 1;
        while (n) {
            if (n & 1)
                product *= x;
            x *= x;
            n /= 2;
        }
        return product;
    }
};