//leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 1;
        int flowers = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            ++flowers;
            if (bloomDay[i] > mid) {
                flowers = 0;
            }
            if (flowers == k) {
                ++bouquets;
                flowers = 0;
            }
            if (bouquets > m)
                return true;
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int res = -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
};