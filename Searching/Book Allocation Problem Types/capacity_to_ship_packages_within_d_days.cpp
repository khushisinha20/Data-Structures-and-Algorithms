//leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& weights, int days_limit, int mid) {
        int sum = 0;
        int days_taken = 1;
        for (int i = 0; i < weights.size(); ++i) {
            if (weights[i] > mid)
                return false;
            sum += weights[i];
            if (sum > mid) {
                sum = weights[i];
                ++days_taken;
                if (days_taken > days_limit)
                    return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *min_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(weights, days, mid)) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
};