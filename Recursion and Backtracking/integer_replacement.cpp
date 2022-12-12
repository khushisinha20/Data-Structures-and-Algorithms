//leetcode.com/problems/integer-replacement/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(long long n, int operations) {
        if (n == 1)
            return operations;
        if (n == 2)
            return operations + 1;
        if (n == 3)
            return operations + 2;
        if (n % 2 == 0)
            return minOperations(n / 2, operations + 1);
        else
            return min(minOperations((n - 1) / 2, operations + 2), minOperations((n + 1) / 2, operations + 2));
    }
    
    int integerReplacement(int n) {
        return minOperations((long long)n, 0);
    }
};