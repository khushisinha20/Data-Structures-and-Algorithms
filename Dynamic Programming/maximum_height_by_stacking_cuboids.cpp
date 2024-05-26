//leetcode.com/problems/maximum-height-by-stacking-cuboids/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBePlaced(vector<int>& cuboid1, vector<int>& cuboid2) {
        return cuboid1[0] >= cuboid2[0] and cuboid1[1] >= cuboid2[1] and cuboid1[2] >= cuboid2[2];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& cuboid: cuboids)
            sort(cuboid.begin(), cuboid.end());

        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        int maxHeight = 0;

        for (int i = 0; i < n; ++i) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; ++j) {
                if (canBePlaced(cuboids[i], cuboids[j])) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};
