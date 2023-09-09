//leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> existing;
        int sum = 0;
        int num = 1;
        
        while (n) {
            int previous = k - num;
            if (existing.find(previous) == existing.end()) {
                sum += num;
                --n;
                existing.insert(num);
            }
            ++num;
        }
        
        return sum;
    }
};