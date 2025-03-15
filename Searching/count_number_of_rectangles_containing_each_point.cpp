//leetcode.com/problems/count-number-of-rectangles-containing-each-point/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> heightBuckets(101);

        for (auto& rectangle: rectangles)
            heightBuckets[rectangle[1]].push_back(rectangle[0]);

        int n = points.size();
        vector<int> count(n, 0);

        for (int height = 1; height <= 100; ++height)
            sort(heightBuckets[height].begin(), heightBuckets[height].end());

        for (int i = 0; i < n; ++i) {
            int xi = points[i][0];
            int yi = points[i][1];
            int total = 0;

            for (int h = yi; h <= 100; ++h) {
                if (heightBuckets[h].empty())
                    continue;
                total += heightBuckets[h].end() - lower_bound(heightBuckets[h].begin(), heightBuckets[h].end(), xi);
            }

            count[i] = total;
        }

        return count;
    }
};
