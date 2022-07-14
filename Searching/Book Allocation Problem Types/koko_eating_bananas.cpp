//leetcode.com/problems/koko-eating-bananas/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int mid) {
        int hours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            if (piles[i] % mid == 0)
                hours += (piles[i] / mid);
            else
                hours += (piles[i] / mid) + 1;
            if (hours > h)
                return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, h, mid)) {
                res = mid;
                high = mid - 1;
            } else 
                low = mid + 1;
        }
        return res;
    }
};