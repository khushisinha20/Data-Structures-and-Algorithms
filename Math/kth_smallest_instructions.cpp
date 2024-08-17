//leetcode.com/problems/kth-smallest-instructions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combination(int n, int r) {
        long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result = result * (n - i + 1) / i;
        }
        return result;
    }

    string kthSmallestPath(vector<int>& destination, int k) {
        int row = destination[0];
        int col = destination[1];
        string result;

        while (row > 0 and col > 0) {
            int n = row + col - 1;
            int r = col - 1;
            int numPathsIfH = combination(n, r);

            if (k <= numPathsIfH) {
                result += 'H';
                --col;
            } else {
                result += 'V';
                k -= numPathsIfH;
                --row;
            }
        }

        result += string(col, 'H');
        result += string(row, 'V');
        return result;
    }
};
