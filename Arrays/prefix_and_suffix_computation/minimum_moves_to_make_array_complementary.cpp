//leetcode.com/problems/minimum-moves-to-make-array-complementary/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int, int> sumFrequency;

        for (int i = 0; i < n / 2; ++i)
            ++sumFrequency[nums[i] + nums[n - i - 1]];

        vector<int> oneMove(2 * limit + 2, 0);
        vector<int> twoMove(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; ++i) {
            int minSum = min(nums[i], nums[n - i - 1]) + 1;
            int maxSum = max(nums[i], nums[n - i - 1]) + limit;

            ++oneMove[minSum];
            --oneMove[maxSum + 1];
            ++twoMove[maxSum + 1];
            --twoMove[2 * limit + 1];
            ++twoMove[2];
            --twoMove[minSum];
        }

        for (int i = 1; i < oneMove.size(); ++i) {
            oneMove[i] += oneMove[i - 1];
            twoMove[i] += twoMove[i - 1];
        }

        for (auto& entry: sumFrequency)
            oneMove[entry.first] -= entry.second;

        int minMoves = INT_MAX;
        for (int i = 2; i <= 2 * limit; ++i)
            minMoves = min(minMoves, oneMove[i] + 2 * twoMove[i]);

        return minMoves;
    }
};
