#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    const int ALPHABET_SIZE = 26;

    vector<vector<int>> multiplyMatrices(vector<vector<int>>& A, vector<vector<int>>& B) {
        int size = A.size();
        vector<vector<int>> result(size, vector<int>(size, 0));

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] = (result[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return result;
    }

    vector<vector<int>> identityMatrix(int size) {
        vector<vector<int>> identity(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i)
            identity[i][i] = 1;
        return identity;
    }

    vector<vector<int>> matrixExponentiation(vector<vector<int>>& transformation, int t) {
        vector<vector<int>> resultMatrix = identityMatrix(ALPHABET_SIZE);
        while (t > 0) {
            if (t & 1)
                resultMatrix = multiplyMatrices(transformation, resultMatrix);
            transformation = multiplyMatrices(transformation, transformation);
            t >>= 1;
        }
        return resultMatrix;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> initialFreq(ALPHABET_SIZE, 0);
        for (char c : s)
            ++initialFreq[c - 'a'];

        vector<vector<int>> transformation(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE, 0));
        for (int current = 0; current < ALPHABET_SIZE; ++current) {
            for (int offset = 1; offset <= nums[current]; ++offset) {
                int targetIndex = (current + offset) % ALPHABET_SIZE;
                ++transformation[targetIndex][current];
            }
        }

        vector<vector<int>> result = matrixExponentiation(transformation, t);
        vector<int> finalFreq(ALPHABET_SIZE, 0);
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            for (int j = 0; j < ALPHABET_SIZE; ++j) {
                finalFreq[i] = (finalFreq[i] + 1LL * result[i][j] * initialFreq[j]) % MOD;
            }
        }

        int finalStringLength = 0;
        for (int count : finalFreq)
            finalStringLength = (finalStringLength + count) % MOD;

        return finalStringLength;
    }
};

