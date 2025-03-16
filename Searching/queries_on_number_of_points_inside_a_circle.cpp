//leetcode.com/problems/queries-on-number-of-points-inside-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distanceSquared(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result(n);
        vector<vector<int>> yBuckets(501);

        for (auto& point: points)
            yBuckets[point[1]].push_back(point[0]);

        for (int i = 0; i <= 500; ++i)
            sort(yBuckets[i].begin(), yBuckets[i].end());

        for (int i = 0; i < n; ++i) {
            int xi = queries[i][0];
            int yi = queries[i][1];
            int ri = queries[i][2];
            int rSquared = ri * ri;
            int count = 0;

            for (int y = max(0, yi - ri); y <= min(500, yi + ri); ++y) {
                if (yBuckets[y].empty())
                    continue;
                int left = xi - ri;
                int right = xi + ri;
                auto low = lower_bound(yBuckets[y].begin(), yBuckets[y].end(), left);
                auto high = upper_bound(yBuckets[y].begin(), yBuckets[y].end(), right);

                for (auto it = low; it != high; ++it) {
                    int x = *it;
                    if (distanceSquared(xi, yi, x, y) <= rSquared)
                        ++count;
                }
            }

            result[i] = count;
        }

        return result;
    }
};
