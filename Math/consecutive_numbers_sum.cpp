//leetcode.com/problems/consecutive-numbers-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        int k = 1;

        while (k * (k - 1) / 2 < n) {
            if ((n - (k * (k - 1)) / 2) % k == 0)
                ++count;
            ++k;
        }

        return count;
    }
};
