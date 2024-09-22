//leetcode.com/problems/k-th-smallest-in-lexicographical-order/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSteps(long long n, long long current, long long next) {
        long long steps = 0;

        while (current <= n) {
            steps += min(n + 1, next) - current;
            current *= 10;
            next *= 10;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        int current = 1;
        --k;

        while (k > 0) {
            int steps = countSteps(n, current, current + 1);
            if (steps <= k) {
                k -= steps;
                ++current;
            } else {
                current *= 10;
                --k;
            }
        }

        return current;
    }
};
