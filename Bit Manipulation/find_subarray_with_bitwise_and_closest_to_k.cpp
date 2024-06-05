//leetcode.com/problems/find-subarray-with-bitwise-and-closest-to-k/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void updateFrequency(int operation, int value, vector<int>& bitFrequency) {
        int i = 0;
        while (value > 0) {
            if (value & 1) {
                bitFrequency[i] += operation;
            }
            value >>= 1;
            ++i;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> bitFrequency(32, 0);
        int n = nums.size();
        int i = 0;
        int j = 0;
        int windowAnd = nums[0];
        int result = INT_MAX;

        while (j < n) {
            windowAnd &= nums[j];
            updateFrequency(1, nums[j], bitFrequency);
            result = min(result, abs(k - windowAnd));

            if (windowAnd > k)
                ++j;
            else if (windowAnd < k) {
                while (i <= j and windowAnd < k) {
                    updateFrequency(-1, nums[i], bitFrequency);
                    ++i;
                    windowAnd = 0;
                    for (int bit = 0; bit < 32; ++bit) {
                        if (j - i + 1 == bitFrequency[bit]) {
                            windowAnd |= (1 << bit);
                        }
                    }
                    result = min(result, abs(k - windowAnd));
                }
                ++j;
            } else
                return 0;
        }

        return result;
    }
};
