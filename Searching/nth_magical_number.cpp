//leetcode.com/problems/nth-magical-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    bool hasNMagicalNumbers(long long mid, long long n, long long a, long long b) {
        long long count = mid / a + mid / b - mid / lcm(a, b);
        return count >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1;
        long long high = 1LL * n * min(a, b);
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (hasNMagicalNumbers(mid, n, a, b)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans % MOD;
    }
};

