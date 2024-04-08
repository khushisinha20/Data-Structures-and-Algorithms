//leetcode.com/problems/maximize-distance-to-closest-person/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int previous = -1;
        int n = seats.size();
        int maxGap = INT_MIN;
        int gapAtBeginning;
        int gapAtEnd = 0;

        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (previous == -1) {
                    previous = i;
                    maxGap = previous;
                    gapAtBeginning = maxGap;
                } else {
                    int gap = i - previous;
                    maxGap = max(maxGap, gap);
                    previous = i;
                }
            }
        }

        if (previous != n - 1) {
            gapAtEnd = n - 1 - previous;
            maxGap = max(maxGap, gapAtEnd);
        }

        int result;
        if (maxGap == gapAtBeginning or maxGap == gapAtEnd)
            result = maxGap;
        else
            result = maxGap / 2;

        return max(result, max(gapAtBeginning, gapAtEnd));
    }
};
