//leetcode.com/problems/closest-dessert-cost/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closest(int a, int b, int& target) {
        if (a == 0)
            return b;

        if (b == 0)
            return a;

        if (abs(target - a) == abs(target - b))
            return a < b ? a : b;

        return abs(target - a) < abs(target - b) ? a : b;
    }

    int dfs(vector<int>& toppingCosts, int index, int totalCostTillNow, int target, vector<vector<int>>& memo) {
        if (index >= toppingCosts.size())
            return totalCostTillNow;

        if (totalCostTillNow > 10000)
            return totalCostTillNow;

        if (memo[index][totalCostTillNow] != -1)
            return memo[index][totalCostTillNow];

        int noTopping = dfs(toppingCosts, index + 1, totalCostTillNow, target, memo);
        int oneTopping = dfs(toppingCosts, index + 1, totalCostTillNow + toppingCosts[index], target, memo);
        int twoToppings = dfs(toppingCosts, index + 1, totalCostTillNow + 2 * toppingCosts[index], target, memo);

        int result = closest(noTopping, closest(oneTopping, twoToppings, target), target);
        memo[index][totalCostTillNow] = result;
        return result;
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX;
        int maxCost = 10000;
        vector<vector<int>> memo(toppingCosts.size(), vector<int>(maxCost + 1, -1));

        for (int baseCost : baseCosts) {
            ans = closest(dfs(toppingCosts, 0, baseCost, target, memo), ans, target);
        }
        return ans;
    }
};
