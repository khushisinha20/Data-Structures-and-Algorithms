//leetcode.com/problems/push-dominoes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string result(n, '.');
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        int time = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R')
                time = 0;
            else if (dominoes[i] == 'L')
                time = -1;
            else if (time != -1)
                ++time;

            if (time != -1)
                right[i] = time;
        }

        time = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L')
                time = 0;
            else if (dominoes[i] == 'R')
                time = -1;
            else if (time != -1)
                ++time;

            if (time != -1)
                left[i] = time;
        }

        for (int i = 0; i < n; ++i) {
            if (left[i] == -1 and right[i] == -1)
                result[i] = dominoes[i];
            else if (left[i] == -1)
                result[i] = 'R';
            else if (right[i] == -1)
                result[i] = 'L';
            else if (left[i] == right[i])
                result[i] = '.';
            else if (left[i] < right[i])
                result[i] = 'L';
            else
                result[i] = 'R';
        }

        return result;
    }
};
