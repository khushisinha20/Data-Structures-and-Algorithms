//leetcode.com/problems/minimum-cost-to-set-cooking-time/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEqual(int source, int target) {
        int mins = source / 100;
        int secs = source % 100;
        return mins * 60 + secs == target;
    }

    long long helper(int current, int moveCost, int pushCost, int target, int lastPressedButton, int moves) {
        if (current > 9999 or moves > 4)
            return INT_MAX;

        if (isEqual(current, target))
            return 0;

        long long result = INT_MAX;

        for (int i = 0; i < 10; ++i) {
            long long ans = (pushCost + (i != lastPressedButton) * moveCost) + helper(current * 10 + i, moveCost, pushCost, target, i, moves + 1);
            result = min(result, ans);
        }

        return result;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        return helper(0, moveCost, pushCost, targetSeconds, startAt, 0);
    }
};
