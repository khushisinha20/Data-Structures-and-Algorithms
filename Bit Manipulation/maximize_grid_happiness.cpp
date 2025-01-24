//leetcode.com/problems/maximize-grid-happiness/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[7][7][7][1 << 6][1 << 6];

    int helper(int rowIndex, int introvertsCount, int extrovertsCount, int prevIntrovertsMask, int prevExtrovertsMask, int m, int n) {
        if (rowIndex >= m)
            return 0;

        if (dp[rowIndex][introvertsCount][extrovertsCount][prevIntrovertsMask][prevExtrovertsMask] != -1)
            return dp[rowIndex][introvertsCount][extrovertsCount][prevIntrovertsMask][prevExtrovertsMask];

        int maxHappiness = INT_MIN;
        for (int introvertsMask = 0; introvertsMask < (1 << n); ++introvertsMask) {
            for (int extrovertsMask = 0; extrovertsMask < (1 << n); ++extrovertsMask) {
                if (introvertsMask & extrovertsMask)
                    continue;

                int introvertsInRow = __builtin_popcount(introvertsMask);
                int extrovertsInRow = __builtin_popcount(extrovertsMask);

                if (introvertsInRow > introvertsCount || extrovertsInRow > extrovertsCount)
                    continue;

                int currentHappiness = introvertsInRow * 120 + extrovertsInRow * 40;
                int prevRowCombinedMask = prevIntrovertsMask | prevExtrovertsMask;
                int combinedMask = introvertsMask | extrovertsMask;

                for (int col = 0; col < n; ++col) {
                    int leftNeighbor = ((combinedMask & (combinedMask >> 1)) >> col) & 1;
                    int rightNeighbor = ((combinedMask & (combinedMask << 1)) >> col) & 1;

                    if ((introvertsMask >> col) & 1) {
                        currentHappiness -= (leftNeighbor * 30 + rightNeighbor * 30);
                        if ((prevRowCombinedMask >> col) & 1)
                            currentHappiness -= 30;
                    }

                    if ((extrovertsMask >> col) & 1) {
                        currentHappiness += (leftNeighbor * 20 + rightNeighbor * 20);
                        if ((prevRowCombinedMask >> col) & 1)
                            currentHappiness += 20;
                    }

                    if (((prevIntrovertsMask >> col) & 1) & ((combinedMask >> col) & 1))
                        currentHappiness -= 30;

                    if (((prevExtrovertsMask >> col) & 1) & ((combinedMask >> col) & 1))
                        currentHappiness += 20;
                }

                maxHappiness = max(maxHappiness, currentHappiness + helper(rowIndex + 1, introvertsCount - introvertsInRow, extrovertsCount - extrovertsInRow, introvertsMask, extrovertsMask, m, n));
            }
        }

        dp[rowIndex][introvertsCount][extrovertsCount][prevIntrovertsMask][prevExtrovertsMask] = maxHappiness;
        return maxHappiness;
    }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        memset(dp, -1, sizeof(dp));
        return helper(0, introvertsCount, extrovertsCount, 0, 0, m, n);
    }
};


