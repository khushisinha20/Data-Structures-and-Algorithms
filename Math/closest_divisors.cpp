//leetcode.com/problems/closest-divisors/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestFactors(int n) {
        for (int i = sqrt(n); i > 1; --i) {
            if (n % i == 0) {
                return {i, n / i};
            }
        }
        return {1, n};
    }
    
    int absoluteDifference(vector<int>& factors) {
        return abs(factors[0] - factors[1]);
    }
    
    vector<int> closestDivisors(int num) {
        vector<int> factorsNumsPlusOne = closestFactors(num + 1);
        vector<int> factorsNumsPlusTwo = closestFactors(num + 2);
        if (absoluteDifference(factorsNumsPlusOne) < absoluteDifference(factorsNumsPlusTwo)) 
            return factorsNumsPlusOne;
        return factorsNumsPlusTwo;
    }
};