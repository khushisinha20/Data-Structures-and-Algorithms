//leetcode.com/problems/powx-n/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPowUtil(double x, long n) {
        if (n == 0)
            return 1;
        
        if (n < 0)
            return 1 / myPowUtil(x, -n);
        
        if (n % 2 == 0)
            return myPowUtil(x * x, n / 2);
        
        return x * myPowUtil(x * x, (n - 1) / 2);
    }
    
    double myPow(double x, int n) {
        return myPowUtil(x, (long)n);
    }
};