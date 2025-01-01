//leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    long long modularExp(long long x, long long n) {
        long long result = 1;

        while (n > 0) {
            if (n & 1)
                result = (result * x) % MOD;
            x = x * x % MOD;
            n >>= 1;
        }

        return result;
    }

    vector<long long> computeFactorials(int n) {
        vector<long long> factorial(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = (factorial[i - 1] * i) % MOD;
        return factorial;
    }

    vector<long long> computeInverseFactorials(vector<long long>& factorial, int n) {
        vector<long long> inverseFactorial(n + 1);
        inverseFactorial[n] = modularExp(factorial[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD;
        return inverseFactorial;
    }

    long long nCr(int n, int r) {
        if (r < 0 or r > n)
            return 0;

        vector<long long> factorial = computeFactorials(n);
        vector<long long> inverseFactorial = computeInverseFactorials(factorial, n);

        return ((factorial[n] * inverseFactorial[r]) % MOD * inverseFactorial[n - r]) % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        int b = n - k;
        long long c = nCr(n - 1, b - 1);
        long long ans = modularExp(m - 1, b - 1);
        ans = (ans * m) % MOD;
        ans = (ans * c) % MOD;
        return ans;
    }
};
