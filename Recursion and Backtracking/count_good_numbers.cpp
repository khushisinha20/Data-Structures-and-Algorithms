//leetcode.com/problems/count-good-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    
    long long power(long long x, long long n) {
        if (n == 0)
            return 1;
        
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= MOD;
        
        if (n % 2 == 1) {
            ans *= x;
            ans %= MOD;
        }
        
        return ans;
    }
    
    int countGoodNumbers(long long n) {
        long long oddPlaces = n / 2;
        long long evenPlaces = n / 2 + n % 2;
        return (power(5, evenPlaces) * power(4, oddPlaces)) % MOD;
    }
};