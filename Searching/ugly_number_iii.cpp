#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    long long countOfUglyNums(long long n, long long a, long long b, long long c) {
        long long ab = lcm(a, b);
        long long bc = lcm(b, c);
        long long ca = lcm(c, a);
        long long abc = lcm(a, bc);
        return n / a + n / b + n / c
             - n / ab - n / bc - n / ca
             + n / abc;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 1;
        long long high = 1e18;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countOfUglyNums(mid, a, b, c) >= n) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};
