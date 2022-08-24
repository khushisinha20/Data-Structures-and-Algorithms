//leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = log10(n) / log10(3);
        while (power >= 0) {
            int num = pow(3, power);
            if (num <= n) 
                n -= num;
            --power;
        }
        return n == 0;
    }
};
