//leetcode.com/problems/count-numbers-with-unique-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        int ans = 10;
        int calc = 9;
        int temp = 9;
        for (int i = 0; i < n - 1; ++i) {
            calc *= temp;
            ans += calc;
            --temp;
        }
        return ans;
    }
};