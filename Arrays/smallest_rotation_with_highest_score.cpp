//leetcode.com/problems/smallest-rotation-with-highest-score/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        vector<pair<int, int>> goodIndices;
        map<int, int> prefixSum;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= i) {
                goodIndices.push_back({0, i - nums[i]});
                goodIndices.push_back({i + 1, nums.size() - 1});
            } else {
                goodIndices.push_back({i + 1, i + (nums.size() - nums[i])});
            }
        }

        for (auto [start, end]: goodIndices) {
            ++prefixSum[start];
            --prefixSum[end + 1];
        }

        int currentSum = 0;
        int rotations = 0;
        int maxSum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            currentSum += prefixSum[i];
            if (currentSum > maxSum) {
                rotations = i;
                maxSum = currentSum;
            }
        }

        return rotations;
    }
};
