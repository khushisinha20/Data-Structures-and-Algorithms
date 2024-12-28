//leetcode.com/problems/maximum-building-height/description/

#include <bits/stdc++.h>
using namespacec std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        for (int i = 1; i < restrictions.size(); ++i) {
            int id = restrictions[i][0];
            int maxHeight = restrictions[i][1];
            int prevId = restrictions[i - 1][0];
            int prevHeight = restrictions[i - 1][1];

            maxHeight = min(maxHeight, prevHeight + id - prevId);
            restrictions[i][1] = maxHeight;
        }

        for (int i = restrictions.size() - 2; i >= 0; --i) {
            int id = restrictions[i][0];
            int maxHeight = restrictions[i][1];
            int nextId = restrictions[i + 1][0];
            int nextHeight = restrictions[i + 1][1];

            maxHeight = min(maxHeight, nextHeight + nextId - id);
            restrictions[i][1] = maxHeight;
        }

        int maxBuildingHeight = 0;
        for (int i = 1; i < restrictions.size(); ++i) {
            int id1 = restrictions[i - 1][0];
            int height1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0];
            int height2 = restrictions[i][1];

            maxBuildingHeight = max(maxBuildingHeight, (height1 + height2 + (id2 - id1)) / 2);
        }

        return maxBuildingHeight;
    }
};
