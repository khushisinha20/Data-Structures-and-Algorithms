//leetcode.com/problems/ugly-number-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        min_heap.push(1);
        int nth = 1;
        long long val = 1;
        while (!min_heap.empty() && nth <= n) {
            val = min_heap.top();
            min_heap.pop();
            while (!min_heap.empty() && min_heap.top() == val)
                min_heap.pop();
            ++nth;
            min_heap.push(val * 2);
            min_heap.push(val * 3);
            min_heap.push(val * 5);
        }
        return val;
    }
};