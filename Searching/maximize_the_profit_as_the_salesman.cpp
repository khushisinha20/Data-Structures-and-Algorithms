#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNextNonOverlappingInterval(vector<vector<int>>& offers, int index) {
        int low = index;
        int high = offers.size() - 1;
        int nextIndex = offers.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (offers[mid][0] > offers[index][1]) {
                nextIndex = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return nextIndex;
    }

    int helper(vector<vector<int>>& offers, int index, vector<int>& dp) {
        if (index >= offers.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int nextIndex = findNextNonOverlappingInterval(offers, index);

        int take = offers[index][2] + helper(offers, nextIndex, dp);
        int notTake = helper(offers, index + 1, dp);

        return dp[index] = max(take, notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        vector<int> dp(offers.size() + 1, -1);
        return helper(offers, 0, dp);
    }
};
