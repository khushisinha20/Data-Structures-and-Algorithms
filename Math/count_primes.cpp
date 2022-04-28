//leetcode.com/problems/count-primes/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count_of_primes = 0;
        for (int i = 2; i < n; ++i)
            if (isPrime[i])
                ++count_of_primes;
        
        return count_of_primes;
    }
};