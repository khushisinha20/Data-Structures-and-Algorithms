//leetcode.com/problems/minimum-space-wasted-from-packaging/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int MOD = 1e9 + 7;
        sort(packages.begin(), packages.end());
        int n = packages.size();
        long long minTotalBoxSize = LLONG_MAX;

        for (auto& boxSizes : boxes) {
            sort(boxSizes.begin(), boxSizes.end());
            if (boxSizes.back() < packages.back()) {
                continue;
            }

            long long totalBoxSize = 0;
            int startIndex = 0;

            for (auto& boxSize : boxSizes) {
                int index = upper_bound(packages.begin() + startIndex, packages.end(), boxSize) - packages.begin() - 1;
                long long countOfFittingBoxes = index - startIndex + 1;
                totalBoxSize += countOfFittingBoxes * boxSize;
                startIndex = index + 1;
            }

            minTotalBoxSize = min(minTotalBoxSize, totalBoxSize);
        }

        if (minTotalBoxSize == LLONG_MAX)
            return -1;

        long long totalPackageSize = accumulate(packages.begin(), packages.end(), 0LL);
        return (minTotalBoxSize - totalPackageSize) % MOD;
    }
};

