//leetcode.com/problems/minimum-time-to-repair-cars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canRepair(vector<int>& ranks, long long time, int cars) {
        long long repairedCars = 0;

        for (int rank: ranks) {
            repairedCars += sqrt(time / rank);
            if (repairedCars >= cars)
                return true;
        }

        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1e18;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canRepair(ranks, mid, cars)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};
