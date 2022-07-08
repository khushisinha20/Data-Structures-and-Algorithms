//practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long start = 0;
        long long end = m - 1;
        long long min_diff = INT_MAX;
        min_diff = min(min_diff, a[end] - a[start]);
        while (end < a.size()) {
            min_diff = min(min_diff, a[end] - a[start]);
            ++end;
            ++start;
        }
        return min_diff;
    }   
};

