//leetcode.com/problems/count-the-number-of-inversions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int helper(int index, int n, unordered_map<int, int>& requirementsMap, int inversions) {
        if (index == n)
            return 1;

        if (inversions > 400)
            return 0;

        if (dp[index][inversions] != -1)
            return dp[index][inversions];

        int sum = 0;

        for (int j = inversions; j <= inversions + index; j++) {
            if (requirementsMap.find(index) != requirementsMap.end() && j != requirementsMap[index])
                continue;

            sum = (sum + helper(index + 1, n, requirementsMap, j)) % MOD;
        }

        return dp[index][inversions] = sum;
    }

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        unordered_map<int, int> requirementsMap;

        for (auto& requirement : requirements)
            requirementsMap[requirement[0]] = requirement[1];

        dp.assign(n, vector<int>(401, -1));

        return helper(0, n, requirementsMap, 0);
    }
};
