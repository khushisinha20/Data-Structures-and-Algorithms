//leetcode.com/problems/maximum-running-time-of-n-computers/\

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& batteries, long long n, long long mid) {
        long long total_duration = 0;
        for (int i = 0; i < batteries.size(); ++i) {
            total_duration += min((long long) batteries[i], mid);
            if (total_duration >= n * mid)
                return true;
        }
        return false;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1;
        long long high = 0;
        for (int i = 0; i < batteries.size(); ++i)
            high += (long long) batteries[i];
        long long res = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(batteries, n, mid)) {
                res = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return res;
    }
};