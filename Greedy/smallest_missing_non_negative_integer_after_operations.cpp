//leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int normalize(int num, int& value) {
        return ((num % value) + value) % value;
    }

    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> normalizedFreq;

        for (int& num: nums) {
            ++normalizedFreq[normalize(num, value)];
        }

        for (int mex = 0; ; ++mex) {
            int remainder = mex % value;
            if (normalizedFreq[remainder] > 0)
                --normalizedFreq[remainder];
            else
                return mex;
        }

        return -1;
    }
};
