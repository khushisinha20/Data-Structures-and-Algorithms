//leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total_ones = count(nums.begin(), nums.end(), 1);
        int total_zeroes = count(nums.begin(), nums.end(), 0);
        if (total_ones == nums.size() || total_ones == 0)
            return 0;
        int start = 0;
        int zeroes_in_window = 0;
        int min_zeroes_in_window = INT_MAX;
        int n = nums.size();
        for (int end = 0; end < 2 * n; ++end) {
            if (nums[end % n] == 0)
                ++zeroes_in_window;
            while (end - start + 1 == total_ones) {
                min_zeroes_in_window = min(min_zeroes_in_window, zeroes_in_window);
                if (nums[start % n] == 0)
                    --zeroes_in_window;
                ++start;
            }
        }
        return min_zeroes_in_window;
    }
};