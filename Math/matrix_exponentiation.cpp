//leetcode.com/problems/fibonacci-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        vector<vector<long long>> result(2, vector<long long> (2));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]);
                }
            }
        }

        a = result;
    }

    void matrixPower(vector<vector<long long>>& matrix, long long n) {
        vector<vector<long long>> result = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1)
                multiply(result, matrix);
            multiply(matrix, matrix);
            n >>= 1;
        }
        matrix = result;
    }

    int fib(int n) {
        if (n == 0)
            return 0;
        vector<vector<long long>> fibMatrix = {{1, 1}, {1, 0}};
        matrixPower(fibMatrix, n - 1);
        return fibMatrix[0][0];
    }
};
