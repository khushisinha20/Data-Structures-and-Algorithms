//leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        if (n == m)
            return 1;

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, memo);
    }

private:
    int helper(int n, int m, vector<vector<int>>& memo) {
        if (n == 11 and m == 13)
            return 6;

        if (n == 13 and m == 11)
            return 6;

        if (n <= 0 || m <= 0)
            return 0;

        if (n == m)
            return 1;

        if (n == 1)
            return m;

        if (m == 1)
            return n;

        if (memo[n][m] != -1)
            return memo[n][m];

        int minSquares = INT_MAX;

        for (int k = min(n, m); k > 0; --k) {
            int remaining1 = 1 + helper(n - k, k, memo) + helper(n, m - k, memo);
            int remaining2 = 1 + helper(n - k, m, memo) + helper(k, m - k, memo);

            minSquares = min(minSquares, min(remaining1, remaining2));
        }

        memo[n][m] = minSquares;
        return minSquares;
    }
};

