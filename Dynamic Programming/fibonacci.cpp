//leetcode.com/problems/fibonacci-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        
        int previousOfprevious = 0;
        int previous = 1;
        for (int i = 2; i <= n; ++i) {
            int current = previous + previousOfprevious;
            previousOfprevious = previous;
            previous = current;
        }
        return previous;
    }
};