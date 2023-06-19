//leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> unprocessedIndices;
        int minFlips = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                if (unprocessedIndices.empty() or unprocessedIndices.size() % 2 == 0) {
                    ++minFlips;
                    unprocessedIndices.push(i + k - 1);
                }
            } else {
                if (unprocessedIndices.size() % 2 != 0) {
                    ++minFlips;
                    unprocessedIndices.push(i + k - 1);
                }
            }

            if (!unprocessedIndices.empty() and unprocessedIndices.front() <= i)
                unprocessedIndices.pop();
        }

        return unprocessedIndices.empty() ? minFlips : -1;
    }
};
