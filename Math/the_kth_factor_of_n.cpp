//leetcode.com/problems/the-kth-factor-of-n/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factorList;

        for (int factor = 1; factor * factor <= n; ++factor) {
            if (n % factor == 0) {
                if (factor * factor != n)
                    factorList.push_back(factor);
                if (--k == 0)
                    return factor;
            }
        }

        int size = factorList.size();

        if (k > factorList.size())
            return -1;

        return n / factorList[size - k];
    }
};
