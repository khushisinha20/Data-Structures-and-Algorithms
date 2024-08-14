//leetcode.com/problems/number_of_ways_to_wear_different_hats_to_each_other/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<vector<int>> mapHatToPerson(vector<vector<int>>& hats) {
        int maxHats = 40;
        vector<vector<int>> hatToPerson(maxHats + 1);

        for (int person = 0; person < hats.size(); ++person) {
            for (int hat : hats[person]) {
                hatToPerson[hat].push_back(person);
            }
        }

        return hatToPerson;
    }

    int helper(vector<vector<int>>& hatToPerson, int mask, int index, vector<vector<int>>& dp, int& allMask) {
        if (mask == allMask)
            return 1;

        if (index >= hatToPerson.size())
            return 0;

        if (dp[mask][index] != -1)
            return dp[mask][index];

        int ways = helper(hatToPerson, mask, index + 1, dp, allMask) % MOD;

        for (int person : hatToPerson[index]) {
            if (mask & (1 << person))
                continue;
            ways = (ways + helper(hatToPerson, mask | (1 << person), index + 1, dp, allMask)) % MOD;
        }

        return dp[mask][index] = ways;
    }

    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> hatToPerson = mapHatToPerson(hats);
        int n = hats.size();
        int allMask = (1 << n) - 1;
        vector<vector<int>> dp(allMask + 1, vector<int>(hatToPerson.size(), -1));
        return helper(hatToPerson, 0, 0, dp, allMask);
    }
};

