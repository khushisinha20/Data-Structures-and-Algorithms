//leetcode.com/problems/broken-calculator/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                ++target;
            }
            ++res;
        }
        return res + startValue - target;
    }
};