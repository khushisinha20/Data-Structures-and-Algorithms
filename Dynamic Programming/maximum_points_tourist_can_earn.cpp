//leetcode.com/problems/maximum-points-tourist-can-earn/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int city, int day, vector<vector<int>>& dp, int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        if (day >= k)
            return 0;

        if (dp[day][city] != -1)
            return dp[day][city];

        int stay = stayScore[day][city] + helper(city, day + 1, dp, n, k, stayScore, travelScore);

        int travel = INT_MIN;

        for (int nextCity = 0; nextCity < n; ++nextCity) {
            if (nextCity != city) {
                travel = max(travel, travelScore[city][nextCity] + helper(nextCity, day + 1, dp, n, k, stayScore, travelScore));
            }
        }

        return dp[day][city] = max(stay, travel);
    }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> dp(k, vector<int>(n, -1));
        int result = 0;

        for (int city = 0; city < n; ++city) {
            result = max(result, helper(city, 0, dp, n, k, stayScore, travelScore));
        }

        return result;
    }
};

