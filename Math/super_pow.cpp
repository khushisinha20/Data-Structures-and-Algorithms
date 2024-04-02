//leetcode.com/problems/super-pow/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int powMod(int x, int n) {
        int result = 1;
        int MOD = 1337;
        x %= MOD;

        while (n > 0) {
            if (n % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            n /= 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty())
            return 1;

        int lastDigit = b.back();
        b.pop_back();

        int MOD = 1337;
        int part1 = powMod(a, lastDigit) % MOD;
        int part2 = powMod(superPow(a, b), 10) % MOD;

        return (part1 * part2) % MOD;
    }
};
