//leetcode.com/problems/removing-minimum-number-of-magic-beans/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.rbegin(), beans.rend());
        long long totalSum = accumulate(beans.begin(), beans.end(), 0ll);
        long long minRemoval = LLONG_MAX;
        
        for (int i = 0; i < beans.size(); ++i) {
            long long savedBeans = (long long)beans[i] * (i + 1);
            long long removedBeans = totalSum - savedBeans;
            minRemoval = min(minRemoval, removedBeans);
        }
        
        return minRemoval;
    }
};