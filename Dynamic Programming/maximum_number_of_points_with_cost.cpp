//leetcode.com/problems/maximum-number-of-points-with-cost/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> previous(n);

        for (int col = 0; col < n; ++col)
            previous[col] = points[0][col];

        for (int i = 1; i < m; ++i) {
            vector<long long> current(n);
            vector<long long> left = current;
            vector<long long> right = current;

            left[0] = previous[0];
            for (int j = 1; j < n; ++j)
                left[j] = max(previous[j], left[j - 1] - 1);

            right[n - 1] = previous[n - 1];
            for (int j = n - 2; j >= 0; --j)
                right[j] = max(previous[j], right[j + 1] - 1);

            for (int j = 0; j < n; ++j)
                current[j] = points[i][j] + max(left[j], right[j]);

            previous = current;
        }

        return *max_element(previous.begin(), previous.end());
    }
};
