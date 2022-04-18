//leetcode.com/problems/factorial-trailing-zeroes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0)
            return 0;
        int res = 0;
        int i = 5;
        while (i <= n) {
            res += (n / i);
            i *= 5;
        }
        return res;
    }
};